#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    //code goes here
    int p = 31;
    string s = "ab";
    string t = "abcabcab";
    const int n = s.size(), m = t.size(), MOD = 1e9+7;
    vector<int> power(m), hashT(m + 1, 0);
    power[0] = 1;
    for(int i = 1; i < m; i++) power[i] = (power[i - 1] * p) % MOD;

    for(int i = 1; i <= m; i++){
        hashT[i] = (hashT[i - 1] + ((t[i - 1] - 'a' + 1) * power[i - 1]) % MOD) % MOD;
    }

    int hashS = 0;
    for(int i = 0; i < n; i++){
        hashS = (hashS + ((s[i] - 'a' + 1) * power[i]) % MOD) % MOD;
    }

    for(int i = 0; i + n - 1 < m; i++){
        int curr_hash = (hashT[i + n] - hashT[i] + MOD) % MOD;
        if(curr_hash  == (hashS * power[i]) % MOD) cout << i << " ";
    }
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
