#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; 
    cin >> N;
    
    vector<int> freq(100005,0);
    set<int> arr_set;
    
    for(int i=0,a;i<N;i++) {
        cin >> a;
        ++freq[a];
        arr_set.insert(a);
    }
    vector<int> cumm_freq(100005,0);
    for(set<int>::iterator it=arr_set.begin();it!=arr_set.end();it++){
        //seive method
        for(int j=*it;j<100005;j+=*it)
            cumm_freq[j]+=freq[*it];
    }
    int Q; 
    cin >> Q;
    
    while(Q--){
        
        int x,k; 
        cin >> x >> k;
    
        (cumm_freq[x]>=k)?cout<<"Yes"<<endl:cout<<"No"<<endl;
    }
    return 0;
}
