#include<bits/stdc++.h>
using namespace std;

int main(){

	int n; cin >> n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int ct=0;
	for(int i=0;i<n-1;i++)
		if(arr[i]%2) arr[i]+=1,arr[i+1]+=1,ct+=2;
	bool ans=true;
	for(int i=0;i<n;i++)
		if(arr[i]%2) ans=false;
	(ans)? cout<<ct<<endl:cout<<"NO"<<endl;
	return 0;
}
