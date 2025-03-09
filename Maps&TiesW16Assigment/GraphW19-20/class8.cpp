#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
#include<map>
#include<stack>
using namespace std;
class graph{
    public:
     unordered_map<int, list<int> > adjList;
     void addEdge(int u, int v, bool direction){
        //direction = 1 -> undirected graph
        //direction => 0 -> directed graph;
        adjList[u].push_back(v);
        if(direction == 1) {
            adjList[v].push_back(u);
        }
}
// Strongly Connected compontent
void dfs1(int src, stack<int>& s, unordered_map<int,bool>& vis){
        vis[src] = true;
        for(auto nbr: adjList[src]) {
            if(!vis[nbr]) {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int,bool>& visited, unordered_map<int,list<int> >& adjNew) {
        visited[src] = true;
        cout << src << ", ";

        for(auto nbr: adjNew[src]) {
            if(!visited[nbr] ) {
                dfs2(nbr, visited, adjNew);
            }
        }
    }
     int countSCC(int n) {
        stack<int> s;
        unordered_map<int,bool> visited;
        //find topo ordering
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs1(i,s,visited);
            }
        }
        //reverse all edges
        unordered_map<int,list<int> > adjNew;
        for(auto t: adjList) {
            for(auto nbr: t.second) {
                int u = t.first;
                int v = nbr;
                //v-> u insert
                adjNew[v].push_back(u);
            }
        }
        //traversse using DFS
        int count = 0;
        unordered_map<int,bool> visited2;

        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!visited2[node]) {
                cout << "Printing "<< count+1 << "th SCC: ";
                dfs2(node,visited2, adjNew);
                cout << endl;
                count++;
            }
        }
        return count;
    }
// Q Find Shortest Bridge
// https://leetcode.com/problems/shortest-bridge/description/

void findBridges(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int,bool>& vis, vector<vector<int>>& ans, unordered_map<int, list<int> >& adjList){
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;
            for(auto nbr: adjList[src]) {
            if(nbr == parent)
                continue;
            if(!vis[nbr]) {
                //dfs call
                findBridges(nbr, src, timer, tin, low, vis, ans, adjList);
                //low update
                low[src] = min(low[src], low[nbr]);
                //check for bridge
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    ans.push_back(temp);
                }
            }
            else{
                //node is visited and not a parent
                //low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
     vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int, list<int> > adjList;
           for(int i=0; i<connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<vector<int>> ans;
                    int timer = 1;
                vector<int> tin(n);
                vector<int> low(n);
                unordered_map<int,bool> vis;
        findBridges(0, -1,timer, tin, low, vis, ans,adjList);
        return ans;
    }
};