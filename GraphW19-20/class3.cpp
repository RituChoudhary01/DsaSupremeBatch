/*
Topological sort:-
Topological Sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge (u → v), vertex u comes before vertex v in the ordering.

Kahn’s Algorithm for Topological Sorting (BFS-Based Approach)
Kahn’s Algorithm is a BFS-based method for Topological Sorting of a Directed Acyclic Graph (DAG) using in-degree.

Topological Sorting is only possible for Directed Acyclic Graphs (DAGs).
If we try to apply topological sorting on a Directed Cyclic Graph (DCG), the algorithm will fail because a cycle prevents a valid linear ordering of nodes.

 */
#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;
template <typename T>
class Graph {
public:
unordered_map<T, list<T > > adjList;
    void addEdge(T u, T v, bool direction){
		adjList[u].push_back(v);
		if(direction == 0){
			adjList[v].push_back(u);
		}
	}
    void printAdjacencyList(){
		for(auto node: adjList){
			cout << node.first << "-> " ;
			for(auto neighbour: node.second){
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}
    // topology Sort
    void topoSortDfs(int src,unordered_map<int,bool>&visited,stack<int>&ans){
        visited[src] = true;
        for(auto neighbour: adjList[src]){
            if(!visited[neighbour]){
                topoSortDfs(neighbour,visited,ans);
            }
        }
        ans.push(src);
    }
    void topoSortBfs(int n,vector<int>&ans){
        queue<int>q;
        unordered_map<int,int>indegree;
        // indegree calculate
        for(auto i:adjList){
            int src = i.first;
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        // put all nodes inside queue,which has indegree = 0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        // bfs logic
        while(!q.empty()){
        int fNode = q.front();
        q.pop();
        ans.push_back(fNode);
        for(auto nbr:adjList[fNode]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
 }
};
int main(){
    Graph<int> g;
    int n = 5;
    g.addEdge(0,1,1);
    g.addEdge(0,2,1);
	g.addEdge(1,3,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
    g.printAdjacencyList();
	cout << endl;
    vector<int> ans;
	g.topoSortBfs(n, ans);
    if(ans.size() == n){
		cout << "It is a valid topology sort" << endl;
	}
	else{
		cout << "Cycle Present or Invalid topology sort " << endl;
	}

    cout << "Printing Topological Sort using BFS: " << endl;
	for(auto i: ans) {
		cout << i << ", ";
	}cout << endl;

    unordered_map<int,bool> visited;
	stack<int> ans1;
	for(int i=0; i<n; i++) {
		if(!visited[i] ){
			g.topoSortDfs(i,visited,ans1);
		}
	}
    cout << "Topoloci Sort: " << endl;
	while(!ans1.empty()) {
		cout << ans1.top();
		ans1.pop();
	}
    return 0;

}
