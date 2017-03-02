#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bs(ll low,ll high,ll key,vector<ll>&arr){
    if(low>high)
        return INT_MAX;
    ll mid = (low+high)/2;
    if(arr[mid]==key)
        return min(mid,bs(low,mid-1,key,arr));
    else if(arr[mid]>key)
        return bs(low,mid-1,key,arr);
    else
        return bs(mid+1,high,key,arr);
}
ll solve(vector<ll>&arr,ll start,ll end,map<pair<ll,ll>,ll> &dp){
    if(start>=end)
        return 0;
    if(dp.find({start,end})!=dp.end())
        return dp[{start,end}];
    ll key = arr[end]-arr[start-1]; //total sum of this subArray
    if(key%2)
        return 0;
    key = (key/2)+arr[start-1]; //left half sum
    ll lower = min(end,bs(start,end,key,arr));//find first index where left half sum == right half sum
    if(lower<end && arr[lower]-arr[start-1] == arr[end]-arr[lower+1-1])
        dp[{start,end}] = 1+max(solve(arr,start,lower,dp),solve(arr,lower+1,end,dp));
    return dp[{start,end}];
}
int main(){
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        vector<ll> arr(N+1,0);
        for(int i=1;i<=N;i++)
            cin >> arr[i],arr[i]+=arr[i-1];
        map<pair<ll,ll>,ll> dp;
       cout<<solve(arr,1,N,dp)<<endl;
    }
}
