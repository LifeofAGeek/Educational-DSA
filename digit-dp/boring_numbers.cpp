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

int dp[20][2][2][2];

int f(string& num, int n, bool iseven, bool leadZero, bool tight){

    if(n==0) return 1;

    int &ans=dp[n][iseven][leadZero][tight];
    if(ans!=-1) return ans;

    ans=0;
    if(iseven){
        int dig[5]={0,2,4,6,8};
        int ub=tight?(num[num.size()-n]-'0'):9;
        for(int d:dig){
            if(d<=ub) ans+=f(num,n-1,0,0,tight&(d==ub));
        }
        return ans;
    }
    else{
        int dig[5]={1,3,5,7,9};
        int ub=tight?(num[num.size()-n]-'0'):9;

        if(leadZero){
            ans+=f(num,n-1,0,1,0);
        }

        for(int d:dig){
            if(d<=ub) ans+=f(num,n-1,1,0,tight&(d==ub));
        }
        return ans;
    }
}

void solve(int tc){
    //code goes here
    int L,R; cin>>L>>R;
    L--;
    string l,r;
    l=to_string(L);
    r=to_string(R);
    mem(dp,-1);
    int ans=f(r,r.size(),0,1,1);
    mem(dp,-1);
    ans-=f(l,l.size(),0,1,1);
    cout << "Case #" << tc << ": " << ans << "\n";
}

int32_t main()
{
// auto start = chrono::high_resolution_clock::now();
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
ios_base::sync_with_stdio(false);
cout.tie(NULL);
cin.tie(NULL);
    int t=1,i=0;
    cin>>t;
    while(i<t)
    {
        solve(i+1);
        i++;
    }
// #ifndef ONLINE_JUDGE
//      auto stop = chrono::high_resolution_clock::now();
//     auto duration = chrono::duration_cast<microseconds>(stop - start);
//     cout<<"\n\nExecuted In: "<<duration.count()<<" ms";
// #endif
    return 0;
}
