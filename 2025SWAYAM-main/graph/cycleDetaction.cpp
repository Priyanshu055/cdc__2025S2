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
    vector<bool> visited(n,false);
    function<bool(int,int)> dfs=[&](int node,int parent){
        visited[node]=true;
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,node))
                    return true;
            }
            else if(neighbor!=parent){
                return true;
            }
        }
        return false;
    };
    bool hasCycle=false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfs(i,-1)){
                hasCycle=true;
                break;
            }
        }
    }
    if(hasCycle)
        cout<<"Graph contains cycle"<<endl;
    else
        cout<<"Graph does not contain cycle"<<endl;
    return 0;
}