// bellman Ford - O(V*E)
vi dist(n,1e9);
bool cycle=false;
function<void(int)> bellmanford = [&](int source)-> void{
    dist[source]=0;
    for(int phase=1;phase<=n;phase++){
        // tuple -> from, to, weight
        for(auto [u,v,w]:adj){
            if(dist[v] > dist[u] + w){
                // nth phase to check if there's negative edge weight cycle
                if(phase == n){
                    cycle=true;
                    break;
                }
                else dist[v] = dist[u] + w;
            }
        }
    }
};
bellmanford(1);
if(cycle) cout<<"-ve Cycle detected\n";
else for(auto d:dist) cout<<d<<" ";
