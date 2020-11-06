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
int w[100001],v[1001];
int dp[101][100001];

int helper(int idx, int val){

	if(idx==n) {
		return val==0?0:INT_MAX;
	}

	if(dp[idx][val]!=-1) return dp[idx][val];

	int &ans=dp[idx][val];
	if(v[idx]<=val){
		int pick=w[idx]+helper(idx+1,val-v[idx]);
		int discard=helper(idx+1,val);

		ans=min(pick,discard);
		return ans;
	}
	else{
		ans=helper(idx+1,val);
		return ans;
	}
}

void solve(){
    //code goes here
	cin>>n>>capacity;
	int vmax=0;
	loop(i,0,n){
		cin>>w[i]>>v[i];
		vmax+=v[i];
	}

	mem(dp,-1);

	rloop(i,vmax,0){
		if(helper(0,i)<=capacity){
			cout<<i;
			break;
		}
	}
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