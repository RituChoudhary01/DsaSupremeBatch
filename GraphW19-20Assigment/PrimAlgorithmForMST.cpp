// Prim Algorithm
/*
Prim Algo:- TO find minimum spanning tree
Spanning tree:-
1.Convert graph to a tree(No cycle)
2.In tree,every node should be reachable by every other node.
3.Tree would have n nodes and n-1 edges.
*/
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric> 
using namespace std;

class Solution {
public:
    int getMinValueNode(vector<int>& key, vector<bool>& mst) {
        int temp = INT_MAX, index = -1;
        for (int i = 0; i < key.size(); i++) {
            if (!mst[i] && key[i] < temp) {
                temp = key[i];
                index = i;
            }
        }
        return index;
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int> > adj[]) {
        vector<int> key(V, INT_MAX);  // Key values to pick minimum weight edge
        vector<bool> mst(V, false);   // To track nodes in MST
        vector<int> parent(V, -1);    // Stores MST structure
        key[0] = 0;

        for (int count = 0; count < V; count++) {
            int u = getMinValueNode(key, mst);
            if (u == -1) break; // In case of disconnected graph
            
            mst[u] = true; // Include node in MST

            // Process all adjacent nodes of u
            for (auto edge : adj[u]) {
                int v = edge[0], w = edge[1];
                if (!mst[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                }
            }
        }
        // Calculate MST total weight
        int sum = accumulate(key.begin(), key.end(), 0);
        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int> > adj[V];

    // Example graph
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[2].push_back({3, 1});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});
    
    Solution obj;
    cout << "MST Weight Sum: " << obj.spanningTree(V, adj) << endl;
    return 0;
}
