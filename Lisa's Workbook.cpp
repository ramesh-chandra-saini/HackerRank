#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k; cin >> n >> k;
    int t[n]; 
    for(int i=0;i<n;i++)
       cin >> t[i];
   int page = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int start = 1,end = 1;
        do{
           end = start+min(k-1,t[i]-1); //min of k problem or left over problem
           //now you have numbering [start....end]
           //count if problem number is special
            ++page; //one more page added to book
           ans+=(start<=page and page<=end);
          t[i]-=k; //k problem covered
          start = end+1; //next page problem start number with end+1 if any remain
        }while(t[i]>0);
    }
    cout<<ans<<endl;
    return 0;
}
