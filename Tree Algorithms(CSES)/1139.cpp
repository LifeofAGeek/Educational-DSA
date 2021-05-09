#include<bits/stdc++.h>
using namespace std;
#define int long long
 
using pset = unordered_set<int>*;
 
pset merge(pset a, pset b) {
    if (a->size() < b->size()) swap(a, b);
    for (auto c : *b) a->insert(c);
    return a;
}
 
void solve(){
    //code goes here
    int n; cin>>n;
    vector<int> tree[n+1];
    int color[n+1] = {0};
    for(int i=1;i<=n;i++) cin>>color[i];
 
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
 
    vector<int> vis(n+1,0), map(n+1);
    function<pset(int)> dfs = [&](int v) -> pset {
        vis[v] = true;
        pset p = new unordered_set<int>;
        p->insert(color[v]);
        for (int u : tree[v]) {
            if (!vis[u]) {
                auto pp = dfs(u);
                p = merge(p, pp);
            }
        }
        map[v] = p->size();
        return p;
    };
    dfs(1);
    for(int i=1;i<=n;i++) cout<<map[i]<<" ";
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
