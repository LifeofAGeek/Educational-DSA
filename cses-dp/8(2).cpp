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
#define dbg(x) cerr << #x << " :: " << x << endl;
#define dbg2(x, y) cerr << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define MOD 1000000007
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
 
void solve(){
    //code goes here
    int n,m; cin>>n>>m;
    int arr[n+1];
    loop(i,1,n) cin>>arr[i];
 
    //dp[i][x] -> number of valid arrays of size i if at i'th idx i kept x.
    int dp[n+1][m+2];
    mem(dp,0);
 
    loop(i,1,n){
        loop(x,1,m){
 
            if(i==1){
                if(arr[i]==0 or arr[i]==x){
                    dp[i][x]=1;
                }
                else dp[i][x]=0;
            }
            else{
                if(arr[i]==0 or arr[i]==x){
                    dp[i][x]=(dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1])%MOD;
                }
                else{
                    dp[i][x]=0;
                }
            }
        }
    }
 
 
    int ans=0;
    loop(i,1,m){
        (ans+=dp[n][i])%=MOD;
    }
 
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