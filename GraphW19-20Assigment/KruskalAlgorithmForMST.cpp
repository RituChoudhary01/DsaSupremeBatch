// Minimum Spanning Tree - Kruskal's Algorithm
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/0
#include <iostream>
#include<vector>
using namespace std;

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);  // Path compression
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    void getMeEdges(int V, vector<vector<int>> adj[], vector<vector<int>>& edges) {
        for (int u = 0; u < V; u++) {
            for (auto edge : adj[u]) {
                int v = edge[0];
                int w = edge[1];
                if (u < v)  // Avoid duplicate edges in an undirected graph
                    edges.push_back({w, u, v});  // Storing weight first for sorting
            }
        }
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> parent(V), rank(V, 0);
        for (int u = 0; u < V; u++) parent[u] = u;

        vector<vector<int>> edges;
        getMeEdges(V, adj, edges);

        // Sort edges based on weight (Kruskal's requires sorting)
        sort(edges.begin(), edges.end());

        int ans = 0;
        for (auto& edge : edges) {
            int w = edge[0], u = edge[1], v = edge[2];
            if (findParent(parent, u) != findParent(parent, v)) {
                unionSet(u, v, parent, rank);
                ans += w;
            }
        }
        return ans;
    }

int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    // Example Graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});

    cout << "MST Weight Sum: " << spanningTree(V, adj) << endl;
    return 0;
}
