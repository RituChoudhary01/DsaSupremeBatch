#include <iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
#include<algorithm>
#include<set>
#include<limits.h>
using namespace std;


class graph {
	public:
	unordered_map<int, list<pair<int,int> > > adjList;
    void addEdge(int u, int v, int wt, bool direction){
		//direction = 1 -> undirected graph
		//direction = 0 -> directed graph;
		adjList[u].push_back(make_pair(v,wt));
		if(direction == 1) {
			adjList[v].push_back(make_pair(u,wt));
		}
	}
    void printAdjList() {
		for(auto i: adjList) {
			cout << i.first <<"-> ";
			for(auto j: i.second) {
				cout << "(" << j.first<<", "<<j.second<<"), ";
			}
			cout << endl;
		}
	}
   // Floyd Warshal algorithm
    void floydWarshal(int n){
		vector<vector<int> > dist(n , vector<int>(n,1e9));
		//diagnol pr zero mark krdo
		for(int i=0; i<n; i++) {
			dist[i][i] = 0;
		}
		//graph k according dist insert krdia h
		for(auto t: adjList) {
			for(auto nbr: t.second) {
				int u = t.first;
				int v = nbr.first;
				int wt = nbr.second;
				dist[u][v] = wt;
			}
		}
        for(int helper=0; helper<n; helper++) {
			for(int src =0; src<n; src++) {
				for(int dest=0; dest<n; dest++) {
					dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
				}
			}
		}
        cout << "Printing distance array: " << endl;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << dist[i][j]<< ", ";
			}
			cout << endl;
		}
		
	}
    // Bellman Ford Algorithm   
    void bellmanFordAlgo(int n, int src) {
		//assuming directed weightted graph
		vector<int> dist(n, INT_MAX);
		dist[src] = 0;
		//n-1 relaxation step
		for(int i=0; i<n-1; i++) {
			//for all edges
			for(auto t: adjList) {
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
			}
		} 
        //to check for -ve cycle
		bool negativeCycle = false;
		for(auto t: adjList) {
				for(auto nbr: t.second) {
					int u = t.first;
					int v = nbr.first;
					int wt = nbr.second;
					if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						negativeCycle = true;
						break;
					}
				}
			}
        if(negativeCycle == true) 
			cout << "-ve cycle present"<<endl;
		else
			cout << "-ve cycle absent"<<endl;

		cout << "printing dist array: ";
		for(auto i : dist)
			cout << i << " ";
		}
};


int main() {
	graph g;
	g.addEdge(0,1,4,0);
    g.addEdge(1,4,6,0);
    g.addEdge(3,4,2,0);
    g.addEdge(4,3,4,0);
    g.addEdge(2,3,3,0);
    g.addEdge(3,2,1,0);
    g.addEdge(2,0,2,0);
    g.addEdge(0,3,5,0);
    g.addEdge(4,0,1,0);
    g.addEdge(1,2,1,0);
	
    g.printAdjList();
	g.floydWarshal(5);

	g.bellmanFordAlgo(5, 0);
}