#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int dp[21][500][2];

int f(int idx, int sum, int tight, vector<int>& num, int& k){
    if(idx == num.size()) return (int)sum == 0;

    if(dp[idx][sum][tight] != -1) return dp[idx][sum][tight];

    int ans = 0, limit;

    if(tight == 0) limit = num[idx];
    else limit = 9;


    for(int i = 0; i <= limit; i++){
        int new_tight = (tight == 0 && i < limit) ? 1 : tight;
        ans += f(idx + 1, (sum + i)% k, new_tight, num, k);
        ans %= MOD;
    }

    if(ans < 0) ans += MOD;

    return dp[idx][sum][tight] = ans;
}


void solve(){
    //code goes here
    string n;
    cin>>n;
    int k; cin>>k;

    int len = n.size();
    vector<int> num(len);
    for(int i=0;i<len;i++) num[i] = n[i] - '0';

    memset(dp, -1, sizeof(dp));
    cout<<f(0,0,0,num,k);

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
