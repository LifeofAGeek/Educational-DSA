// dijkstra algorithm - O(ELogV)
vi dist(n+1,1e9);
function<void(int)> dijkstra = [&](int source)-> void{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // weight, vertex
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        for(auto [v,w] : adj[u]){
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
};
dijkstra(0);
