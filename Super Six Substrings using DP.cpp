#include<bits/stdc++.h>
using namespace std;
int N;
string str;
long long dp[100005][7];
long long solve(int i,int rem=0){

    if(i==N)
        return 0;

    if(dp[i][rem]!=-1)
        return dp[i][rem];

    int new_rem = (rem*10+str[i]-'0')%6;
    return  dp[i][rem]=(new_rem==0)+solve(i+1,new_rem);

}
int main(){

    cin >> str;

    N = str.length();

    memset(dp,-1,sizeof(dp));
    
    long long ans = 0;
    for(int i=0;i<N;i++){
        if(str[i]=='0')
            ans+=1; //only one allowed
        else
            ans+=solve(i);//solve for all substring
                            //starting with ith char
    }
    cout<<ans<<endl;
}
