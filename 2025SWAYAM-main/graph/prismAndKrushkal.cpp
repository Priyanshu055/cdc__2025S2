#include <bits/stdc++.h>
using namespace std;

// Structure for edges
struct Edge {
    int src, dest, weight;
};

// Union-Find structure for Kruskal's algorithm
class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (rank[px] < rank[py]) parent[px] = py;
        else if (rank[px] > rank[py]) parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

// Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });
    UnionFind uf(V);
    vector<Edge> mst;
    for (auto& edge : edges) {
        if (uf.unite(edge.src, edge.dest)) {
            mst.push_back(edge);
        }
    }
    return mst;
}

// Prim's algorithm
vector<Edge> primMST(vector<vector<pair<int, int>>>& graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    pq.push({0, 0}); // {weight, vertex}

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    vector<Edge> mst;
    for (int i = 1; i < V; i++) {
        mst.push_back({parent[i], i, key[i]});
    }
    return mst;
}

// Function to print MST
void printMST(const vector<Edge>& mst) {
    cout << "Edges in MST:\n";
    for (auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

int main() {
    // Sample graph with 4 vertices
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    // For Prim's, convert to adjacency list
    vector<vector<pair<int, int>>> graph(V);
    for (auto& edge : edges) {
        graph[edge.src].push_back({edge.dest, edge.weight});
        graph[edge.dest].push_back({edge.src, edge.weight});
    }

    cout << "Kruskal's MST:\n";
    vector<Edge> kruskalMst = kruskalMST(edges, V);
    printMST(kruskalMst);

    cout << "\nPrim's MST:\n";
    vector<Edge> primMst = primMST(graph, V);
    printMST(primMst);

    return 0;
}
