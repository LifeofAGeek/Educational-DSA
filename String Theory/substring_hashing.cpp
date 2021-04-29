#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;

int dp[1000001];
int inv[1000001];
 
int power(int a , int n)
{
    int result = 1;
 
    while(n)
    {
        if(n & 1) result = (result * a) % MOD;
        n >>= 1;
        a = (a * a) % MOD;
    }
    return result;
}
 
 
void init(string input_string)
{
    int p = 31;
    int p_power = 1;
    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);
 
 
    for(int i=1;i<input_string.size();i++)
    {
        char ch = input_string[i];
 
        p_power = (p_power * p) % MOD;
        inv[i] = power(p_power , MOD - 2);
 
        dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % MOD;
    }
}
 
int substringHash(int L , int R)
{
    int result = dp[R];
 
    if(L > 0) result -= dp[L-1];
 
    result = (result * inv[L]) % MOD;
 
    return result;
}

void solve(){
    //code goes here
    string s;
    cin>>s;
    // pre-processing !
    init(s);
    int l,r; cin>>l>>r; // s[l..r]
    cout<<substringHash(l,r);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
