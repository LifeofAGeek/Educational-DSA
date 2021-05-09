#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int> tree[200001];
int res[200001];
int subSize[200001];
int subDist[200001];
int n;
 
void dfs1(int node , int par)
{
    subSize[node] = 1;
    
    for(int child : tree[node])
    if(child != par)
    {
        dfs1(child , node);
        subSize[node] += subSize[child];
        
        subDist[node] += subSize[child] + subDist[child];
    }
}
 
void dfs2(int node , int par)
{
    res[node] = res[par] - subSize[node] - subDist[node] + n - subSize[node] + subDist[node];
    
    for(int child : tree[node])
    if(child != par)
    dfs2(child , node);
}
 
void solve(){
    //code goes here
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs1(1,0);
    res[1] = subDist[1];
    for(int child: tree[1]){
        dfs2(child,1);
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
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
