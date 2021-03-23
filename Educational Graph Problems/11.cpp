// Euler graph - Hierholzer's algorithm for Directed Graphs

void solve(){
    //code goes here
    int n,m; cin>>n>>m;
    vector<int> graph[n];
    int u,v;
    vector<int> in(n), out(n);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        in[v]++; out[u]++;
        graph[u].push_back(v);
    }

    auto isEuler = [&]()-> bool{
        int start = 0, end = 0;
        for(int i=0;i<n;i++){
            // for sure not a euler graph
            if(abs(in[i]-out[i]) > 1) return false;
            // extra outgoing edge -> start node
            else if(out[i]-in[i]==1) start++;
            // extra incoming edge -> end node
            else if(in[i]-out[i]==1) end++;
        }
        // either euler circuit or condition of path
        return (start==0 and end==0) or (start==1 and end==1);
    };

    auto findStartNode = [&]()-> int{
        int start = 0;
        for(int i=0;i<n;i++){
            // unique starting point
            if(out[i]-in[i]==1) return i;
            // prevent singleton vertex to become the start node
            if(out[i]>0) start=i;
        }
        return start;
    };

    vector<int> path;
    function<void(int)> dfs = [&](int at)-> void{
        // while the current node still has outgoing edge
        while(out[at]!=0){
            // find the next unvisited outgoing edge
            int next = graph[at][--out[at]];
            dfs(next);
        }
        // add the current node to the path
        path.push_back(at);
    };

    if(not isEuler()){
        cout<<"Not and Euler Graph";
        return;
    }
    else{
        int start = findStartNode();
        dfs(start);
        reverse(begin(path),end(path));
        for(auto node:path) cout<<node<<" ";
    }
}
