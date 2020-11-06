/**
	Author:  Anubhav Sethi
	Created: 2020-11-05 20:59
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

int dp[3001][3001]; // dp[i][j] - at ith idx of S and jth idx of T.
int choice[3001][3001];
// choice 0 -> (i-1,j), 1 -> (i,j-1), 2 -> pick and goto (i-1,j-1).
void solve(){
    //code goes here
  	string s,t;
  	cin>>s>>t;
  	int n=s.size(), m=t.size();

  	dp[0][0]=0;

  	if(s[0]==t[0]){
  		dp[0][0]=1;
  		choice[0][0]=2;
  	}

  	loop(i,0,n){
  		loop(j,0,m){ 
  			// not picking current element
  			if(i>0){
  				dp[i][j]=dp[i-1][j];
  				choice[i][j]=0;
  			}
  			if(j>0){
  				if(dp[i][j-1]>dp[i][j]){
  					dp[i][j]=dp[i][j-1];
  					choice[i][j]=1;
  				}
  			}

  			// pick current if equal
  			if(s[i]==t[j]){
  				int ans=1;
  				if(i>0 and j>0) ans=1+dp[i-1][j-1];
  				if(ans>dp[i][j]) {
  					dp[i][j]=ans;
  					choice[i][j]=2;
  				}
  			}
  		}
  	}
  	// cout<<dp[n-1][m-1];

  	int i=n-1,j=m-1;
  	string subseq="";
  	while(i>=0 and j>=0){
  		if(choice[i][j]==0){
  			i--;
  		}
  		else if(choice[i][j]==1){
  			j--;
  		}
  		else if(choice[i][j]==2){
  			subseq.push_back(s[i]); // or t[j]
  			i--; j--;
  		}
  	}

  	reverse(all(subseq));
  	cout<<subseq;
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