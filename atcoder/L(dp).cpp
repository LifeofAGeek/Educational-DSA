/**
	Author:  Anubhav Sethi
	Created: 2020-11-07 17:43
**/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i <= end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define vi vector<int>
#define vec(x) vector<x>
#define sz(v) (int)v.size() 
#define UB upper_bound
#define LB lower_bound
#define all(v) (v).begin(),(v).end()
#define arl(v) (v).rbegin(),(v).rend()
#define fsp(a) fixed<<setprecision(a)
#define mem(a,with) memset(a, with, sizeof (a))
#define vmn(a) (*min_element(a.begin(),a.end()))   
#define vmx(a) (*max_element(a.begin(),a.end()))
#define bs(a,key) binary_search(all(a),key)    /// return bool.
#define rotl(a,x) rotate(a.begin(),a.begin()+x,a.end());
#define rotr(a,x) rotl(a,a.size()-x);
#define nl cout<<endl
#define MOD 1000000007
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}

// 2*X - sum  ->  X
int dp[3001][3001][2]; // resulting value of X
 
// dp[L][R][p] = (L....R) inclusive, pth player turn
// p = 0 -> first, p = 1 -> second
 
// base cases
// dp[i][i][0] = a[i]
// dp[i][i][1] = 0
 
// Transitions
// pick L or pick R
// dp[L][R][0] = max(a[L] + dp[L+1][R][1],
// 					a[R] + dp[L][R-1][1])
// dp[L][R][1] = min(dp[L+1][R][0],
// 					dp[L][R-1][0])
 
// Order of Evaluation
// increasing of (R-L)
 
// ans = 2*(dp[0][n-1][0]) - sum

void solve(){
    //code goes here
    int n; cin>>n;
    int a[n];
    int sum=0; 
    for(auto &x:a){
    	cin>>x;
    	sum+=x;
    }

    loop(i,0,n-1){
    	dp[i][i][0]=a[i];
    	dp[i][i][1]=0;
    }

    for(int RminusL = 1; RminusL < n; RminusL++){
		for(int L = 0; L + RminusL < n; L++){
			int R = L + RminusL;
			// player 1
			dp[L][R][0] = max(a[L] + dp[L+1][R][1],a[R] + dp[L][R-1][1]);
			// player 2
			dp[L][R][1] = min(dp[L+1][R][0], dp[L][R-1][0]);
		}
	}

    int x=dp[0][n-1][0]; // (0...n-1) first player move
    int ans=2*x - sum;

    cout<<ans;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}