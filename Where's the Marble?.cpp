#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<int> arr(11,0);
    arr[m]=1;
    while(n--){
        int a,b; cin >> a >> b;
        swap(arr[a],arr[b]);
    }
    for(int i=1;i<=10;i++){
        
        if(arr[i])
            cout<<i<<endl;
    }
    
    return 0;
}
