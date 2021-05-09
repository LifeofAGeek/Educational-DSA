#include<bits/stdc++.h>
using namespace std;
#define int long long

int helper(int arr[], int n)
{
    vector<pair<int,int>> dp(n); // sum, len
    dp[0].first = arr[0];
    dp[0].second = 1;
    int mxlen = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i].second = 1;
        for (int j = 0; j < i; j++)
        {
            if (dp[i].first < dp[j].first and arr[i] >= arr[j] and dp[i].second < dp[j].second + 1) {
                dp[i].first = dp[j].first;
                dp[i].second = dp[j].second + 1;
            }
        }
        dp[i].first += arr[i];
        mxlen = max(mxlen, dp[i].second);
    }
    int ans = INT_MIN;
    for (auto& x: dp) {
        if(x.second == mxlen){
            ans = max(ans, x.first);
        }
    }
    return ans;
}

void solve(){
    //code goes here
    int n; cin>>n;
    int arr[n];
    for(int& a:arr) cin>>a;

    cout<<helper(arr,n);
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
