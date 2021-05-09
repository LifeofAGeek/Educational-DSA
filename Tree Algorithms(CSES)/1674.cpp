#include<bits/stdc++.h>
using namespace std;
#define int long long
 
void solve(){
    //code goes here
    int n; cin>>n;
    vector<int> tree[n+1];
    int emp = 2;
    for(int i=1;i<n;i++){
        int boss; cin>>boss;
        tree[boss].push_back(emp); // 1->2, 2->1
        tree[emp].push_back(boss);
        emp++;
    }
 
    vector<int> STS(n+1,0);
 
    function<int(int,int)> dfs = [&](int u, int p)-> int{
        int currSize = 1;
        for(int v:tree[u]){
            if(v!=p){
                currSize += dfs(v,u);
            }
        }
        STS[u] = currSize-1;
        return currSize;
    };
    dfs(1,-1);
    for(int i=1;i<=n;i++) cout<<STS[i]<<" ";
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
