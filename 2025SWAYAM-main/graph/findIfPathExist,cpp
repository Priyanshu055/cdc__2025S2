#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start,end;
    cin>>start>>end;
    vector<bool> visited(n,false);
    function<bool(int)> dfs=[&](int node){
        if(node==end)
            return true;
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor))
                    return true;
            }
        }
        return false;
    };
    if(dfs(start))
        cout<<"Path exists between "<<start<<" and "<<end<<endl;
    else
        cout<<"No path exists between "<<start<<" and "<<end<<endl;
    return 0;
}