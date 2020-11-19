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
 
int dp[1000][1000];
 
void solve(){
    //code goes here
    int n; cin>>n;
 
    int vis[n][n];
 
    loop(i,0,n-1){
    	loop(j,0,n-1){
    		char ch; cin>>ch;
    		if(ch=='.') vis[i][j]=0;
    		else vis[i][j]=1;
    	}
    }
 
    dp[0][0]=1;
 
    loop(i,0,n-1){
    	loop(j,0,n-1){
    		if(vis[i][j]){
    			dp[i][j]=0;
    			continue;
    		}
    		if(i>0) {
    			dp[i][j]+=dp[i-1][j];
    			dp[i][j]%=MOD;
    		}
    		if(j>0) {
    			(dp[i][j]+=dp[i][j-1])%MOD;
    			dp[i][j]%=MOD;
    		}
    	}
    }
 
    cout<<dp[n-1][n-1];
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