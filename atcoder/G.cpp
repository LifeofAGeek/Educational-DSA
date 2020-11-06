/**
	Author:  Anubhav Sethi
	Created: 2020-11-06 17:52
**/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i < end; i++)
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

vi g[100005];
int dp[100005];
bool vis[100005];

void visit(int vertex){
	vis[vertex]=1;
	// choice 1 - stop at the same vertex
	dp[vertex]=0;
	for(auto child:g[vertex]){
		if(!vis[child]){
			visit(child);
		}
		// choice 2 - move to its child
		dp[vertex]=max(dp[vertex],1+dp[child]);
	}	
}

void solve(){
    //code goes here
    int n,m; cin>>n>>m;
    loop(i,0,m){
    	int u,v;
    	cin>>u>>v;
    	g[u].push_back(v);
    }

    loop(i,1,n+1){
    	if(!vis[i]){
    		visit(i);
    	}
    }

    int ans=0;
    loop(i,1,n+1){
    	ans=max(ans,dp[i]);
    	// cout<<dp[i]<<" ";
    }
    // nl;
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