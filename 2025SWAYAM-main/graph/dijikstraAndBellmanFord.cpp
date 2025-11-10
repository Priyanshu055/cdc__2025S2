#include <bits/stdc++.h>
using namespace std;

// Dijkstra's Algorithm for shortest path in graph with non-negative weights
vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Bellman Ford Algorithm for shortest path, handles negative weights, detects negative cycles
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycles
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains negative cycle" << endl;
            return {};
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);
    vector<vector<int>> edges;

    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        edges.push_back({u, v, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    // Dijkstra
    vector<int> distDijk = dijkstra(V, adj, src);
    cout << "Dijkstra distances from " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (distDijk[i] == INT_MAX) cout << i << ": INF" << endl;
        else cout << i << ": " << distDijk[i] << endl;
    }

    // Bellman Ford
    vector<int> distBF = bellmanFord(V, edges, src);
    if (!distBF.empty()) {
        cout << "Bellman Ford distances from " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            if (distBF[i] == INT_MAX) cout << i << ": INF" << endl;
            else cout << i << ": " << distBF[i] << endl;
        }
    }

    return 0;
}
