// Leetcode 1334
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/description/
#include <iostream>
#include<list>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

int Dijkstra(int src, int n, unordered_map<int, list<pair<int, int>>>& adjList, int distanceThreshold) {
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert({0, src});
    int reachableCities = 0;
    
    while (!st.empty()) {
        auto top = *st.begin();
        st.erase(st.begin());
        int nodeDist = top.first;
        int node = top.second;
        
        if (node != src && nodeDist <= distanceThreshold)
            reachableCities++;
        
        // Update neighbor distances
        for (auto nbr : adjList[node]) {
            int currDist = nodeDist + nbr.second;
            if (currDist < dist[nbr.first]) {
                auto it = st.find({dist[nbr.first], nbr.first});
                if (it != st.end())
                    st.erase(it);
                
                dist[nbr.first] = currDist;
                st.insert({dist[nbr.first], nbr.first});
            }
        }
    }
    return reachableCities;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    
    int city = -1;
    int minReachableCities = INT_MAX;
    
    for (int u = 0; u < n; u++) {
        int reachableCitiesCount = Dijkstra(u, n, adjList, distanceThreshold);
        if (reachableCitiesCount <= minReachableCities) {
            minReachableCities = reachableCitiesCount;
            city = u;
        }
    }
    return city;
}
