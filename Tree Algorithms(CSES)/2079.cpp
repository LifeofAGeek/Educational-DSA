#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    //code goes here
    int n; cin>>n;
    vector<int> tree[n];
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    vector<int> STS(n,0);
 
    function<int(int,int)> dfs1 = [&](int u, int p)-> int{
        int currSize = 1;
        for(int v:tree[u]){
            if(v!=p){
                currSize += dfs1(v,u);
            }
        }
        STS[u] = currSize;
        return currSize;
    };
    dfs1(0,-1);
    function<int(int,int)> dfs2 = [&](int u, int p)-> int{
        for(int v:tree[u]){
            if(v!=p and STS[v]>n/2){
                return dfs2(v,u);
            }
        }
        return u;
    };
    cout<<dfs2(0,-1)+1;
}
 
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
