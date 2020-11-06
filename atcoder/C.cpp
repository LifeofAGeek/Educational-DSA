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

const int N=1e5+1;

int n;
int arr[N][3], dp[N][3];

void solve(){
    //code goes here
    cin>>n;
    loop(i,0,n){
    	loop(j,0,3) cin>>arr[i][j];
    }

    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];

    loop(day,1,n){
    	dp[day][0]=arr[day][0]+max(dp[day-1][1],dp[day-1][2]);
    	dp[day][1]=arr[day][1]+max(dp[day-1][0],dp[day-1][2]);
    	dp[day][2]=arr[day][2]+max(dp[day-1][0],dp[day-1][1]);
    }

    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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