/*
Graph:-A graph in data structure is a non-linear data structure that consists of nodes (vertices) and edges that connect them.
Directed Graph:-A directed graph (digraph) is a type of graph where the edges have a direction.
Undirected Graph:-A undirected graph is a type of graph where the edges have a no direction.
weighted Undirected Graph:- Each edge In a Undirected graph  has a numerical value is called weight.
weighted Directed Graph:- Each edge In a directedgraph  has a numerical value is called weight.
degree of Undirected Graph:- In an undirected graph, the degree of a vertex is the number of edges connected to it. Since edges are bidirectional, each edge contributes 1 to the degree of both of its endpoints.
For any undirected graph, the sum of the degrees of all vertices is twice the number of edges.
           ∑degree of all vertices = 2×number of edges
indegree :- In-degree of a vertex v is The number of edges directed towards v.
outdegree:-Out-degree of a vertex v is The number of edges directed away from v.
Path:- A path in a graph is a sequence of vertices where each consecutive pair of vertices is connected by an edge.
cyclic Graph:-A cyclic graph is a graph that contains at least one cycle. A cycle is a path where the starting and ending vertex are the same.
Acyclic Graph:- An acyclic graph is a graph that does not contain any cycles.

Graph Implementation:-
1.using Adjacency Matrix
2.using Adjacency List.
Traversal of Graph:-
1.BFS(Breath First search)traversal.
2.DFS(depth first search)traversal.
In an undirected graph there can be maximum n*(n-1)/2 edges.and total number of undirected graph with n vertices is 2^(n*(n-1)/2).
n-1 is maximun edges in an acylic undirected graph with n vertices.
DFS is most efficiently determine the presence of cycle in a given graph.


*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T,list<T > >adjList;
    // add Edges in Directed graph.
    void addEdgeD(T u,T v){
        adjList[u].push_back(v);
    }
    // add Edges in Undirected graph.
     void addEdge(T u,T v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    } 
    // Print Adjacency List.
    void printAdjacencyList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
    // BFS treversal 
    void bfs(int src,unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";
            // insert neighbours
            for(auto ngb: adjList[frontNode]){
                if(!visited[ngb]){
                    q.push(ngb);
                    visited[ngb] = true;
                }
            }
        }
    }
    // DFS traversal
    void dfs(int src,unordered_map<int,bool>&visited){
        cout<<src<<", ";
        visited[src] = true;
        for(auto ngb:adjList[src]){
            if(!visited[ngb]){
                dfs(ngb,visited);
            }
        }
    }
};
 class GraphWeight {
public:
	unordered_map<int, list<pair<int,int> > > adjList;
   
	void addEdge(int u, int v,int weight, bool direction) {
		//direction = 0 -> undirected graph
		//direction = 1 -> directed graph
		//create an edge from u to v
		adjList[u].push_back({v,weight});
		if(direction == 0)
		{
			//undirected edge
			//create an edge from v to u
			adjList[v].push_back({u,weight});
		}
	}
// print adjList with weight edges
	void printAdjacencyList() {
		for(auto node: adjList) {
			cout << node.first << "-> " ;
			for(auto neighbour: node.second) {
				cout <<"("<<neighbour.first<<","<<neighbour.second<<"), ";
			}
			cout << endl;
		}
	}
};


int main(){
  Graph<int> g;
  int n = 5;
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(2,4);
  g.addEdge(1,3);
  cout<<"AdjList of Graph: "<<endl;
  g.printAdjacencyList();
  cout << endl;  
 unordered_map<int, bool>visited;
 // run a loop for all nodes connected or diconnected
  cout << "Printing BFS Traversal: " << endl;
  for(int i=0; i<n; i++){
    if(!visited[i]){
      g.bfs(i, visited);
    }
    }
  cout << endl << "Printing DFS Traversal: " << endl;
  unordered_map<int, bool> visited2;
  for(int i=0; i<n; i++){
    if(!visited2[i]){
      g.dfs(i, visited2);
    }
    }
  Graph<char> g1;
  g1.addEdge('a','b');
  g1.addEdge('b', 'c');
  g1.addEdge('a', 'c');
  g1.printAdjacencyList();

}
/*
// Print Adj Matrix of Graph
int main(){
int n;
  cout << "Enter the number of nodes: " << endl;
  cin >> n;

  vector<vector<int> > adj(n, vector<int>(n,0));

  int e;
  cout << "Enter the number of edges: " << endl;
  cin >> e;
  
  for(int i=0; i<e; i ++) {
   int u,v;
   cin >> u >> v;
   adj[u][v] = 1;
  }

  //printing Adj Matrix
  for(int i=0; i<n; i++) {
   for(int j =0; j<n; j++) {
     cout << adj[i][j] << " ";
   }
   cout << endl;
  }
  return 0;
}
*/

 