#include<bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i < end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define vi vector<int>
#define vec(x) vector<x>
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


int n,capacity;
int w[101],v[101];
int dp[101][100001];

int helper(int idx, int weight){

	if(idx==n or weight==0) return 0;
	if(dp[idx][weight]!=-1) return dp[idx][weight];

	int &ans=dp[idx][weight];
	if(w[idx]<=weight){
		int pick=v[idx]+helper(idx+1,weight-w[idx]);
		int discard=helper(idx+1,weight);

		ans=max(pick,discard);
		return ans;
	}
	else{
		ans=helper(idx+1,weight);
		return ans;
	}
	
}

void solve(){
    //code goes here
	cin>>n>>capacity;
	loop(i,0,n){
		cin>>w[i]>>v[i];
	}

	mem(dp,-1);

	cout<<helper(0,capacity);

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