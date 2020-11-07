/**
	Author:  Anubhav Sethi
	Created: 2020-11-07 13:29
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


// DP on Impartial Games
void solve(){
    //code goes here
    int n,k; cin>>n>>k;
   	int arr[n]; // unlimited supply of set A
   	loop(i,0,n-1) cin>>arr[i];

   	bool dp[k+1]={false}; // 0 ... k stones all false initially
   	// dp[i] -> true if the player playing with i stones will win else false.
   	dp[0]=false; // base case

   	loop(stone,1,k){
   		for(auto x:arr){
   			if(stone-x>=0 and dp[stone-x]==false){ // agar mai ek state ko pick kr ke losing state mea ja sakta hu
											// iska matlb that stone is a winning state for 1'st player - toro. 
   				dp[stone]=true;
   				break;
   			}
   		}
   	}

   	// loop(i,0,k) cout<<dp[i]<<" ";
   	// nl;

   	cout<<(dp[k]?"First":"Second");
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