/**
	Author:  Anubhav Sethi
	Created: 2020-11-07 18:32
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
const int MOD=1000000007;
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}

// DP on Contiguous Segments

int dp[401][401];
int arr[401];
int prefix[401];

int f(int l, int r){
	if(l==r) return 0;

	if(dp[l][r]!=-1) return dp[l][r];

	int ans=LLONG_MAX;

	int cost=prefix[r]-prefix[l]+arr[l];

	loop(x,l,r-1){
		ans=min(ans,cost+f(l,x)+f(x+1,r));
	}

	return dp[l][r]=ans;
}

void solve(){
    //code goes here
    int n; cin>>n;
	loop(i,0,n-1) cin>>arr[i];

	prefix[0]=arr[0];
	loop(i,1,n-1){
		prefix[i]=prefix[i-1]+arr[i];
	}

	mem(dp,-1);

	int ans=f(0,n-1);
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