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
 
void solve(){
    //code goes here
    int n; cin>>n;
    vi arr1,arr2;
    for(int i=1;i<=n;i+=2){
    	arr1.push_back(i);
    }
    for(int i=2;i<=n;i+=2){
    	arr1.push_back(i);
    }
    for(int i=2;i<=n;i+=2){
    	arr2.push_back(i);
    }
    for(int i=1;i<=n;i+=2){
    	arr2.push_back(i);
    }
    bool flag1=1,flag2=1;
 
    for(int i=1;i<arr1.size();i++){
    	if(abs(arr1[i]-arr1[i-1])==1){
    		flag1=0;
    		break;
    	}
    }
    for(int i=1;i<arr2.size();i++){
    	if(abs(arr2[i]-arr2[i-1])==1){
    		flag2=0;
    		break;
    	}
    }
    if(!flag1 and !flag2) cout<<"NO SOLUTION";
    else if(flag1) for(int x:arr1) cout<<x<<" ";
    else if(flag2) for(int x:arr2) cout<<x<<" ";
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