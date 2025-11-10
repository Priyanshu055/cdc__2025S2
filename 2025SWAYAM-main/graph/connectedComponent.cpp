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
    int connected_components=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            connected_components++;
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int neighbor:adj[node]){
                    if(!visited[neighbor]){
                        visited[neighbor]=true;
                        q.push(neighbor);
                    }
                }
            }
        }
    }
    cout<<connected_components<<endl;
    return 0;
}