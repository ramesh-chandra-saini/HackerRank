#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define CHUNK 10000000
#define CHUNK_START  2222222
#define CHUNK_STOP   7777777
#define CHUNK_BEFORE 777777

ll MAX = (ll)sqrt(1e15);
vector<ll> primeList;
void sieve(){
    vector<bool> isPrime(MAX+1,true);
    for(ll i=2;i*i<=MAX;i++)
        if(isPrime[i])
            for(ll j=i*i;j<=MAX;j+=i)
                isPrime[j]=false;
    for(ll i=2;i<=MAX;i++)
        if(isPrime[i])
            primeList.push_back(i);
}
bool isMegaPrime(ll N){
    ll dig = N%10;
    if(dig != 2 && dig != 3 && dig != 5 && dig != 7 )
        return false;
  return (N>10)?isMegaPrime(N/10):true;
}
ll countMegaPrimes(ll first,ll last,ll count_prime=0){
    if(first>last) //invalid range
        return 0;
    vector<int> IsPrime(last-first+1,true);
    for(ll i=0;i<primeList.size();i++){
        ll p = primeList[i];
        if(p*p>last) //you're done with sqrt(last)
            break;
        for(ll j=max(p,(first+p-1)/p)*p;j<=last;j+=p)
                IsPrime[j-first]=false;
    }
    for(ll i=first;i<=last;i++)
        if(IsPrime[i-first] && isMegaPrime(i))//checking mega prime
            ++count_prime;
    return count_prime;
}
int main(){
    //getPrimesTill();
    sieve();//preprocessing
    ll L,R,ans=0;
    cin >> L >> R;
    if(R<=CHUNK_BEFORE){
        ans+=countMegaPrimes(L,R);
    }else{
        if(L<=CHUNK_BEFORE){
            ans+=countMegaPrimes(L,CHUNK_BEFORE);
            L=CHUNK_BEFORE+1;
        }
        for( ll start=(L/CHUNK)*CHUNK+CHUNK_START,stop;start<=R;start+=CHUNK){
            if(isMegaPrime(start)){
                stop  = start-CHUNK_START+CHUNK_STOP;
                ans+=countMegaPrimes(max(L,start),min(R,stop));
            }
        }
    }
    cout<<ans<<endl;
}
