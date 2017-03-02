#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    string s;
    cin >> s;

    vector<ll> rem(3,0);
    rem[0]=1; //mark freq of 0 as one ....for an obvious reason
    ll pre = 0,ans;

    for(int i=0; i<s.size(); i++){
        pre = (pre*10 + s[i] - '0')%3;

        if((s[i]-'0')%2==0)
            ans+=rem[pre];
        if(s[i]!='0')
            ++rem[pre];
    }

    cout << ans << endl;

    return 0;
}
