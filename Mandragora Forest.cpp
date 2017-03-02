#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() { 
    int t; cin >> t;
    while(t--){
    	int n; cin >> n ;
    	ll arr[n],sum=0;
    	for(int i=0;i<n;i++) cin >> arr[i],sum+=arr[i];
    	sort(arr,arr+n);
    	long long int P=sum,S=1;
    	for(int i=0;i<n;i++){
    		sum-=arr[i];
    		S+=1;
    		P=max(P,S*sum);
    	}
    	cout<<P<<endl;
    }
    return 0;
}
