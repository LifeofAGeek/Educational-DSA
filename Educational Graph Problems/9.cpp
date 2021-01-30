int solve(vector<vector<int>>& graph) {
    int timer=0,n=graph.size();
    vector<int> tin(n,-1),low(n,-1);
    int ans=0;
    vector<bool> vis(n,0);
    function<void(int,int)> dfs=[&](int u, int p)-> void{
        vis[u]=1;
        tin[u]=timer;
        low[u]=timer;
        timer++;
        for(auto v:graph[u]){
            if(v==p) continue;
            if(vis[v]){
                low[u]=min(low[u],tin[v]);
            }
            else{
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]>tin[u]){
                    ans++;
                }
            }
        }
    };
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,-1);
    }
    return ans;
}
