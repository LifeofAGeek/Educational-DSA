#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    //code goes here
    int n,m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> vis(n+1,0), currStack;

    function<void(int,int)> dfs = [&](int u, int p)-> void{
        vis[u] = 1;
        currStack.push_back(u);

        for(int& v:graph[u]){
            if(vis[v] == 0) dfs(v,u);
            else if(vis[v] == 1){
                if(v != p){
                    cout<<"cycle\n";
                    cout<<v<<" ";
                    int i = currStack.size() - 1;
                    while(i >= 0 and currStack[i] != v){
                        cout<<currStack[i--]<<" ";
                    }
                    cout<<endl;
                }
            }
        }

        vis[u] = 2;
        currStack.pop_back();
    };

    dfs(1,-1);

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

/*
Input
6 7
1 2
2 3
1 3
3 5
1 4
2 6
4 6

Output
cycle
1 3 2 
cycle
1 4 6 2 
*/
