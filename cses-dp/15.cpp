#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
#define int long long
#define loop(i, start, end) for (int i = start; i <= end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define read(a,n) loop(i,0,n-1) cin>>a[i];
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

// weighted Interval Scheduling - DP

struct job{
    int s,f,p;
};

bool cmp(job a, job b){ // finish time 
    return a.f < b.f;
}

int BS(job arr[],int i){
    int l=0,h=i-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(arr[m].f<arr[i].s){
            if(arr[m+1].f<arr[i].s) l=m+1;
            else return m;
        }
        else{
            h=m-1;
        }
    }
    return -1;  
}

void solve(){
    //code goes here
    int n; cin>>n;
    job arr[n];
    loop(i,0,n-1){
        cin>>arr[i].s>>arr[i].f>>arr[i].p;
    }

    sort(arr,arr+n,cmp);

    vi dp(n,0);
    dp[0]=arr[0].p; //base case

    loop(i,1,n-1){
        //include current job + all valid previous jobs
        int incl=arr[i].p;
        int idx=BS(arr,i);
        if(idx!=-1){
            incl+=dp[idx];
        }
        //exclude the current job and only have all previous jobs
        int excl=dp[i-1];

        dp[i]=max(incl,excl);
    }

    cout<<dp[n-1];
}

int32_t main()
{
auto start = chrono::high_resolution_clock::now();
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
#ifndef ONLINE_JUDGE
     auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<microseconds>(stop - start);
    cout<<"\n\nExecuted In: "<<duration.count()<<" ms";
#endif
    return 0;
}
