// Eventual Safe States
// https://www.geeksforgeeks.org/problems/eventual-safe-states/0

#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    bool checkCyclicDirectedGraphUsingDfs(vector<int> adj[], int src, unordered_map<int, bool>& visited,unordered_map<int, bool>& dfsVisited, vector<int>& safenodes) {
        visited[src] = true;
        dfsVisited[src] = true;
        safenodes[src] = 0;  // Assume initially it's not a safe node

        for (auto nbr : adj[src]) {
            if (!visited[nbr]) {
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(adj, nbr, visited, dfsVisited, safenodes);
                if (aageKaAnswer) return true;
            }
            if (dfsVisited[nbr]) {
                return true;  // Cycle detected
            }
        }

        dfsVisited[src] = false;
        safenodes[src] = 1;  // Mark as a safe node
        return false;
    }

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> ans;
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsVisited;
        vector<int> safenodes(V, -1);  // -1 means unprocessed

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                checkCyclicDirectedGraphUsingDfs(adj, i, visited, dfsVisited, safenodes);
            }
        }

        for (int i = 0; i < V; i++) {
            if (safenodes[i] == 1) ans.push_back(i);
        }
        return ans;
    }

int main() {
    int V = 5;
    vector<int> adj[V];

    // Example directed graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Cycle here
    adj[4].push_back(2);

    vector<int> safeNodes = eventualSafeNodes(V, adj);

    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
