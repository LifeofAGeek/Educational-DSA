#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int rolling_hash(string& s){
    int hash = 0, p = 31, p_power = 1; // A prime p >= |character set|
    for(char& ch:s){
        hash = (hash + (ch-'a'+1)*p_power)%MOD;
        p_power = (p*p_power)%MOD;
    }
    return hash;
}

void solve(){
    //code goes here
    string s;
    cin>>s;
    cout<<rolling_hash(s);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
