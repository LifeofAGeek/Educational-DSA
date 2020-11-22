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

string s1,s2;
int n,m;
int dp[5001][5001];


//recursive + memo
int f(int i,int j){

    if(i==n) return m-j;
    if(j==m) return n-i;

    int &ans=dp[i][j];
    if(ans!=-1) return ans;

    ans=0;
    if(s1[i]==s2[j]){
        ans=f(i+1,j+1);
    }
    else{
        ans=1+min({f(i+1,j+1),f(i+1,j),f(i,j+1)});
    }

    return ans;
}

void solve(){
    //code goes here
    cin>>s1>>s2;
    n=s1.size(); m=s2.size();

    // mem(dp,-1);

    if(n==0){
        cout<<m;
        return;
    }
    if(m==0){
        cout<<n;
        return;
    }

    // cout<<f(0,0);

    loop(i,1,n){
        dp[i][0]=i;
    }
    loop(i,1,m){
        dp[0][i]=i;
    }

    loop(i,1,n){
        loop(j,1,m){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }

    cout<<dp[n][m];
    
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