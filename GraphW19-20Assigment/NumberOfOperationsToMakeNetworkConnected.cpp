// Minimize connections
// https://www.geeksforgeeks.org/problems/minimize-connections/0
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);

        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            }
            else if (rank[u] > rank[v]) {
                parent[v] = u;
            } 
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    int makeConnected(int n, vector<vector<int> >& connections) {
        if (connections.size() < n - 1) return -1; // Not enough edges to connect all components

        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        int noExtraEdges = 0;
        for (auto& connection : connections) {
            int u = findParent(parent, connection[0]);
            int v = findParent(parent, connection[1]);

            if (u != v) {
                unionSet(u, v, parent, rank);
            } else {
                noExtraEdges++;
            }
        }

        int nocc = 0; // Number of connected components
        for (int i = 0; i < n; i++) {
            if (findParent(parent, i) == i) nocc++; // Correctly count components
        }

        int ans = nocc - 1;
        return (noExtraEdges >= ans) ? ans : -1;
    }
    int main() {
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    int n = 4;

    int result = makeConnected(n, connections);
    cout << "Minimum operations to connect the network: " << result << endl;
    return 0;
}