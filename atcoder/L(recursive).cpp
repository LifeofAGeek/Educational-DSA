/**
	Author:  Anubhav Sethi
	Created: 2020-11-07 13:59
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

// DP with Minimax Algorithm on Games
int n;
int a[3005];
int dp[3005][3005];

int helper(int l, int r, int turn){

	if(l==r){ // base case.
		return (1-turn)*a[l]; // turn 0 is player 1 & turn 1 is player 2
	}

	int &ans= dp[l][r];

	if(ans!=-1) return ans;

	if(turn){ // second players turn
		ans=min(helper(l+1,r,!turn),helper(l,r-1,!turn));
	}
	else{ // first player turn
		ans=max(a[l]+helper(l+1,r,!turn),a[r]+helper(l,r-1,!turn));
	}

	return ans;
}

void solve(){
    //code goes here
    int sum=0;
    cin>>n;
    loop(i,0,n) {
    	cin>>a[i];
    	sum+=a[i];
    }

    mem(dp,-1);

    // x-y -> player 1 will maximize and vise versa
    // x+y = sum , y = sum - x
    // x - (sum - x) = 2*x - sum

    int x=helper(0,n-1,0);
    int y=sum-x;

    cout<<x-y; // or just 2*x - sum
    // nl;
    // cout<<2*x-sum;
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