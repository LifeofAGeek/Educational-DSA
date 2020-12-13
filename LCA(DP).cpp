const int MAX=1e5+1;
const int maxN = log(MAX);
vi adj[MAX]; // adj list
vi vis(MAX,0); // visited array
vi level; // height of each node
vi p; // parent array
int lca[MAX][maxN];
int n;

// linear time
void findParent(int root){
    queue<pair<pair<int,int>,int>> q;
    q.push({{root,-1},1}); // root is parent of itself

    while(!q.empty()){
        pair<pair<int,int>,int> node = q.front(); // child, parent, level
        q.pop();
        level[node.f.f]=node.s;
        p[node.f.f]=node.f.s;
        lca[node.f.f][0]=node.f.s;
        vis[node.f.f]=1;
        for(auto child:adj[node.f.f]){
            if(!vis[child]){
                q.push({{child,node.f.f},node.s+1});
                lca[child][0]=node.f.f;
            }
        }
    }

    for(int i=1;i<=maxN;i++){
        for(int j=1;j<=MAX;j++){
            if(lca[j][i-1]!=-1){
                lca[j][i]=lca[lca[j][i-1]][i-1];
            }
        }
    }
}

// multiple query 
int find(int x){
    return p[x];
}

// union by rank hueristics 
int Union(int x, int y){
    return 0;
}

void solve(){
    //code goes here
    cin>>n; // n nodes
    p.resize(n+1,-1);
    level.resize(n+1,0);
    mem(lca,-1);
    loop(i,1,n-1){ // n-1 edges
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    findParent(1); // construct

    // loop(i,1,n){
    //     cout<<p[i]<<" ";
    // }

    function<int(int,int)> LCA = [&](int a, int b)-> int{

        if(level[a]>level[b]) swap(a,b);

        int diff=level[b]-level[a];

        while(diff>0){
            int i=log(diff);
            b=lca[b][i];
            diff-=(1<<i);
        }

        if(a==b) return a;

        for(int i=log(n);i>=0;i--){
            if(lca[a][i]!=-1 and (lca[a][i]!=lca[b][i])){
                a=lca[a][i];
                b=lca[b][i];
            }
        }
        return p[a];
        // while(a!=b){
        //     a=lca[a][0];
        //     b=lca[b][0];
        // }
        // return b;
    };

    //O(n*logn*Q)
       auto dist = [&](int a, int b){
           return (level[a]+level[b]-2*level[LCA(a,b)]);
       };

       cout<<dist(1,8);
}
