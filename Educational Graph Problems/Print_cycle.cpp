void solve(){
    //code goes here
    int n,m; cin>>n>>m;
    vi adj[n];
    loop(i,0,m-1){
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vi deg(n,0), vis(n,0);
    loop(i,0,n-1) deg[i]=adj[i].size();

    queue<int> q;
    loop(i,0,n-1){
    	if(deg[i]==1) q.push(i);
    }
    while(!q.empty()){
    	int u = q.front();
    	q.pop();
    	vis[u] = 1;

    	for(int v:adj[u]){
    		if(!vis[v] and --deg[v]==1) q.push(v);
    	}
    }
    bool cycle = false;
    loop(i,0,n-1) {
    	if(!vis[i]) {
    		cycle = true;
    		break;
    	}
    }

    if(!cycle) cout<<"No cycle bruh\n";
    else{
    	loop(i,0,n-1){
    		if(!vis[i]) cout<<i<<" ";
    	}
    }
}
