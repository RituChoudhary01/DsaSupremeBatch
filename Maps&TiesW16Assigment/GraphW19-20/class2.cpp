#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph {
public:
unordered_map<T, list<T > > adjList;

	void addEdge(T u, T v, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed graph
		//create an edge from u to v
		adjList[u].push_back(v);
		if(direction == 0)
		{
			//undirected edge
			//create an edge from v to u
			adjList[v].push_back(u);
		}
	}

    void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<neighbour<<", ";
			}
			cout << endl;
		}
	}
    // Q1. Check Cyclic Using BFS in Undirected Graph
    bool checkCyclicUsingBfs(int src,unordered_map<int,bool>& visited){
        queue<int>q;
        unordered_map<int,int>parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr: adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if (nbr != parent[frontNode]){ 
                return true;
            }

            }
        }
        return false;
    }
    // Q2.Check Cyclic Using DFS in Undirected Graph
    bool checkCyclicUsingDfs(int src,unordered_map<int,bool>&visited,int parent){
        visited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool checkAageKaAns = checkCyclicUsingDfs(nbr,visited,src);
                if(checkAageKaAns == true) return true;
            }
            else if(visited[nbr]&&nbr!=parent){
                return true;
            }
        }
        return false;
    }
    // Q3.Check Cyclic Using DFS in directed Graph
    bool checkCyclicDirectedGraphUsingDfs(int src,unordered_map<int,bool>& visited,unordered_map<int,bool>dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;
        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                bool aageKaAnswer = 
                checkCyclicDirectedGraphUsingDfs(nbr,visited,dfsVisited);
                if(aageKaAnswer == true) return true;
            }
            if(visited[nbr] == true && dfsVisited[nbr] == true){
                return true;
            }
        }
        dfsVisited[src] = false;
        return false;
    }
};
int main(){
    Graph<int> g;
    int n = 5;
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);
	g.addEdge(4,0,1);
    g.printAdjacencyList();
	cout << endl;
    cout<<"check Cycle is Present in Directed Graph using DFS: ";
	bool ans = false;
	unordered_map<int, bool> visited;
	unordered_map<int, bool> dfsVisited;
	for(int i=0; i<n; i++) {
		if(!visited[i] ) {
			ans = g.checkCyclicDirectedGraphUsingDfs(i,visited,dfsVisited);
			if(ans == true)
				break;
		}
	}
    if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;
    Graph<int> g1;    
    n = 6;
    g1.addEdge(0,1,0);
	g1.addEdge(1,2,0);
	g1.addEdge(1,4,0);
	g1.addEdge(5,3,0);
	g1.addEdge(1,5,0);
    g1.addEdge(5,4,0);
    g1.printAdjacencyList();
	cout << endl;
    cout<<"check Cycle is Present in UnDirected Graph using BFS: ";
    ans  = false;
    unordered_map<int, bool> visited1;
    for(int i=0; i<n; i++) {
		if(!visited1[i] ) {
			ans = g1.checkCyclicUsingBfs(i,visited1);
			if(ans == true)
				break;
		}
	}
    if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

      cout<<"check Cycle is Present in UnDirected Graph using DFS: "; 
      ans  = false;
    unordered_map<int, bool> visited2;
    for(int i=0; i<n; i++){
		if(!visited2[i] ){
			ans = g1.checkCyclicUsingDfs(i,visited2,-1);
			if(ans == true)
				break;
		}
	}
    if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl; 
    return 0;     
}