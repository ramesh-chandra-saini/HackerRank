#include<bits/stdc++.h>
using namespace std;
map<char,int> idx;
bool isBaseCase(string &stt,vector<int>&total_f,int N){
    for(int i=0;i<4;i++)
        if(total_f[i]!=N/4)
            return false;
    return true;
}
bool isPossible(int window,string &str,vector<int>&total_f,int N){

    vector<int> window_f(4,0);
    for(int i=0;i<window-1;i++)//process till w-1 width..
        ++window_f[idx[str[i]]];

    for(int i=window-1,k=0;i<N;i++,k++){
        ++window_f[idx[str[i]]];//add char to window

        vector<int> rem_f(4,0);
        for(int j=0;j<4;j++)//remove window char from original string
            rem_f[j]=total_f[j]-window_f[j];

        bool isPossible=true;
        //checking ....if still any char have freq more than N/4..than current window cann't help
        for(int j=0;j<4;j++)
            if(rem_f[j]>N/4)
                isPossible=false;
        if(isPossible)
            return true;
       --window_f[idx[str[k]]];//remove char
    }
    return false;
}
int main() {
    idx['A']=0,idx['C']=1,idx['G']=2,idx['T']=3;
    int N; cin >> N;
    string str; cin >> str;

    vector<int> total_f(4,0);
    for(int i=0;i<N;i++)//Total Freq of A,C,G,T
        ++total_f[idx[str[i]]];

    if(isBaseCase(str,total_f,N)){ //check for base case
        cout<<0<<endl;
        return 0;
    }
    int low=1,high=N,ans;
    while(low<=high){
        int mid = (low+high)/2;
        if(isPossible(mid,str,total_f,N))
            ans=mid,high=mid-1;
        else
            low=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}
