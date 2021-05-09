#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int> tree[200001];
int n;
 
void solve(){
    //code goes here
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int A, B, mxdist = -1;
    bool found = false;
 
    function<void(int,int,int)> dfs = [&](int u, int d, int p)-> void{
        if(d >= mxdist){
            mxdist = d;
            if(!found) A = u;
            else B = u;
        }
        for(int v : tree[u]){
            if(v != p){
                dfs(v,d+1,u);
            }
        }
    };
 
    dfs(1,0,0);
    found = true;
    dfs(A,0,0);
 
    int distA[n+1], distB[n+1];
 
    function<void(int,char)> BFS = [&](int u,char who)-> void{
        vector<bool> vis(n+1,0);
        queue<int> q;
        q.push(u);
        vis[u] = 1;
 
        if(who == 'A') distA[u] = 0;
        else distB[u] = 0;
 
        while(!q.empty()){
            int v = q.front();
            q.pop();
 
            for(int child : tree[v]){
                if(!vis[child]){
                    if(who == 'A'){
                        distA[child] = distA[v] + 1;
                    }
                    else{
                        distB[child] = distB[v] + 1;
                    }
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
    };
 
    BFS(A,'A');
    BFS(B,'B');
 
    for(int i=1;i<=n;i++) cout<<max(distA[i],distB[i])<<" ";
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
