#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long dp[200005][9];
int N;
string str;
long long solve(int i,int rem){

    if(i==N)//base case
        return (rem==0);

    if(dp[i][rem]!=-1) //Is already Solved
        return dp[i][rem];

    long long ans = 0;//storing  ans
    ans+=solve(i+1,rem);//skip ith char
    ans+=solve(i+1,(rem*10+(str[i]-'0'))%8);//taking ith char
    return dp[i][rem]=ans%MOD;
}
int main(){

    cin >> N;
    cin >> str;

    memset(dp,-1,sizeof(dp));

    cout<<(MOD+solve(0,0)-1)%MOD<<endl;
    return 0;
}
