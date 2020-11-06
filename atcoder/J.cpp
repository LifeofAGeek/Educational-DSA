/**
	Author:  Anubhav Sethi
	Created: 2020-11-06 22:35
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

const int N = 301;
 
double dp[N][N][N];
// dp[x][y][z] = x 3s, y 2s, z 1s , (n-x-y-z) 0s
 
// dp[x][y][z] = (1 + p3 * dp[x-1][y+1][z] + p2 * dp[x][y-1][z+1] + p1 * dp[x][y][z-1]) / (1 - p0);

void solve(){
    //code goes here
    int n; cin>>n;
    int shushi[4] = {0};

    loop(i,1,n){
    	int x;
    	cin>>x;
    	shushi[x]++;
    }

    dp[0][0][0]=0;

    loop(three,0,n){
    	loop(two,0,n){
    		loop(one,0,n){
    			int zero=n-three-two-one;

    			if(zero==n) continue;

    			if(three+two+one>n) continue;

    			double val = 1;
				// pick 3
				if(three > 0) val += (1.0 * three / n) * dp[three-1][two+1][one];
				// pick 2
				if(two > 0) val += (1.0 * two / n) * dp[three][two-1][one+1];
				// pick 1
				if(one > 0) val += (1.0 * one / n) * dp[three][two][one-1];
				
				dp[three][two][one] = val / (1 - 1.0 * zero / n);
    		}
    	}
    }

    cout<<fsp(9);
    cout<<dp[shushi[3]][shushi[2]][shushi[1]];
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