// Given Q queries and each query have 2 nodes. Find whether one node lies in the subtree of other.
// application : https://codeforces.com/contest/1328/problem/E
/*
Works for both directed and undirected graphs.
The In Time refers to the time when a node is first visited and the out time refers to the time when we finally leave that node, when all the explorations from that node has been done.
Useful for question where it is asked, given two nodes, determine whether they are within each other's subtree or not.
A node which is in the subtree of other would have in_time greater and out_times lesser than the node of which it is under. 
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std::chrono;
using namespace std;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define int long long
#define loop(i, start, end) for (int i = start; i <= end; i++)
#define rloop(i, start, end) for (int i = start; i >= end; i--)
#define read(a,n) loop(i,0,n-1) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
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
#define nl cout<<"\n"
#define dbg(x) cerr << #x << " :: " << x << endl;
#define dbg2(x, y) cerr << #x << " :: " << x << "\t" << #y << " :: " << y << endl;
#define MOD 1000000007
#define f first
#define s second
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}


void solve(){
    //code goes here
    int n,m; cin>>n>>m;
    vi adj[n+1];
    vector<bool> vis(n+1,0);
    vi in(n+1,0),out(n+1,0);
    loop(i,1,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=1;
    function<void(int)> dfs=[&](int u)-> void{
        vis[u]=1;
        in[u]=timer++;
        for(auto next:adj[u]){
            if(!vis[next]){
                dfs(next);
            }
        }
        out[u]=timer++;
    };

    dfs(1);
    int q;
    cin>>q;
    while(q--){
        int x,y; cin>>x>>y;
        if(in[x]<in[y] and out[x]>out[y]) cout<<"YES\n";
        else if(in[y]<in[x] and out[y]>out[x]) cout<<"YES\n";
        else cout<<"NO\n";
    }
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
