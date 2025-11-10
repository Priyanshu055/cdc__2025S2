// bfs traversal and dfs tarversal 

#include<iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void bfs(vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(start);
    visited[start] = true;
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main(){
    int n = 5; // number of nodes
    vector<vector<int>> adj(n);
    // Example graph: 0-1, 0-2, 1-3, 1-4
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    cout << "BFS Traversal: ";
    bfs(adj, 0);
    cout << "DFS Traversal: ";
    dfs(adj, 0);
    return 0;
}
