#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k; cin >> n >> k;
    ll type[n]; for(int i=0;i<n;i++) cin >> type[i];
    ll curr = 0;
    ll Energy = 100;
    //take first move
    curr = (curr+k)%n;
    Energy-=1+(type[curr]==1?2:0);
    
    while(curr!=0){
        curr = (curr+k)%n;
        Energy-=1+(type[curr]==1?2:0);
    }
    cout<<Energy<<endl;
}
