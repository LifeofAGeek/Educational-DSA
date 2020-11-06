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

int n;
vi h;
vi dp;

int helper(int idx){
	if(idx==n-1) return 0;

	if(dp[idx]!=-1) return dp[idx];

	int &ans=dp[idx];
	int choice1,choice2;

	if(idx+1<n)
	choice1=abs(h[idx]-h[idx+1])+helper(idx+1);
	
	if(idx+2<n)
	choice2=abs(h[idx]-h[idx+2])+helper(idx+2);

	ans=min(choice1,choice2);
	return ans;
}

void solve(){
    //code goes here
    cin>>n;
    h.resize(n);
    loop(i,0,n) cin>>h[i];

    dp.resize(n);
    loop(i,0,n) dp[i]=-1;

    cout<<helper(0);

    // dp[0]=0; dp[1]=abs(h[1]-h[0]);
    // loop(i,1,n){
    // 	dp[i]=min(abs(h[i]-h[i-1])+dp[i-1],abs(h[i]-h[i-2])+dp[i-2]);
    // }
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
