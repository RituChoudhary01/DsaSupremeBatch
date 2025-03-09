/*
Q1.Debug the code. Cycle Detection using DSU.

bool findCycle(Graph const &graph, int n)
{
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.MakeSet(n);
 
    // consider every edge (u, v)
    for (int u = 0; u < n; u++)
    {
        // Iter for all adjacent vertices
        for (int v: graph.adjList[u])
        {
            // find the ref of the sets to which elements `u` and `v` belongs
            int x = ds.Find(u);
            int y = ds.Find(v);
 
            // if both `u` and `v` have the same parent, the cycle is found
            if (x == y) {
                return true;
            }
        }
    }
 
    return false;
}
Ans:-
bool findCycle(Graph const &graph, int n)
{
    // initialize Main class
    DisjointSet ds;
 
    // create a singleton set for each element of the universe
    ds.MakeSet(n);
 
    // consider every edge (u, v)
    for (int u = 0; u < n; u++)
    {
        // Recur for all adjacent vertices
        for (int v: graph.adjList[u])
        {
            // find the root of the sets to which elements `u` and `v` belongs
            int x = ds.Find(u);
            int y = ds.Find(v);
 
            // if both `u` and `v` have the same parent, the cycle is found
            if (x == y) {
                return true;
            }
            else {
                ds.Union(x, y);
            }
        }
    }
 
    return false;
}

Q2.Debug the code. Kruskal Algorithm
class Graph {
  private:
  vector<pair<int, edge> > G;
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;

  public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
};
Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep == vRep) {
      T.push_back(G[i]);
      union_set(uRep, vRep);
    }
  }
}
Ans:-
class Graph {
  private:
  vector<pair<int, edge> > G;
  vector<pair<int, edge> > T;  // mst
  int *parent;
  int V;

  public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
};
Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());  // increasing weight
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);  // add to tree
      union_set(uRep, vRep);
    }
  }
}
Q3. Debug the code. Number of Connected Components.
int minimum_key(int k[], int mst[])    
{  
    int minimum  = INT_MAX, min,i;    
    
    for (i = 0; i < vertices; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
    return min;    
}    


void prim(int g[vertices][vertices])    
{    

    int parent[vertices];    
    int k[vertices];       
    int mst[vertices];      
    int i, count,edge, v;
    for (i = 0; i < vertices; i++)  
    {  
        k[i] = 0;  
        mst[i] = INT_MAX;    
    }  
    k[0] = 0;
    parent[0] = -1;
    for (count = 0; count < vertices; count++)    
    {    
        edge = minimum_key(k, mst);    
        mst[edge] = 1;    
        for (v = 0; v < vertices; v++)    
        {  
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])    
            {  
                parent[v]  = edge, k[v] = g[edge][v];    
            }  
        }  
     }    
     printf("\n Edge \t  Weight\n");  
     for (i = 1; i < vertices; i++)    
     	printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
}
Ans:-
int minimum_key(int k[], int mst[])    
{  
    int minimum  = INT_MAX, min,i;    
    
    for (i = 0; i < vertices; i++)  
        if (mst[i] == 0 && k[i] < minimum )   
            minimum = k[i], min = i;    
    return min;    
}    


void prim(int g[vertices][vertices])    
{    

    int parent[vertices];    
    int k[vertices];       
    int mst[vertices];      
    int i, count,edge, v;
    for (i = 0; i < vertices; i++)  
    {  
        k[i] = INT_MAX;  
        mst[i] = 0;    
    }  
    k[0] = 0;
    parent[0] = -1;
    for (count = 0; count < vertices-1; count++)    
    {    
        edge = minimum_key(k, mst);    
        mst[edge] = 1;    
        for (v = 0; v < vertices; v++)    
        {  
            if (g[edge][v] && mst[v] == 0 && g[edge][v] <  k[v])    
            {  
                parent[v]  = edge, k[v] = g[edge][v];    
            }  
        }  
     }    
     printf("\n Edge \t  Weight\n");  
     for (i = 1; i < vertices; i++)    
     	printf(" %d <-> %d    %d \n", parent[i], i, g[i][parent[i]]);    
} 

Q4.Debug the code. Dijkstra Algorithm

int findMinVertex(vector<int> &distance, vector<int> &visited, int v) {
	int minVertex = -1;

	for(int i=0; i<v; i++) {
		if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) minVertex = i;

	return minVertex;
}

void printShortestDistance(vector<vector<int>> &edges, int v){
	vector<int> distance(v, INT_MAX);
	vector<int> visited(v, false);
	distance[0] = 0;

	for(int i=0; i<v; i++) {
		int minVertex = findMinVertex(distance, visited, v);
		for(int j=0; j<v; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]) {
					distance[j] = dist;
				}
			}
		}
	}

	for(int i=0; i<v; i++) cout << i << " " << distance[i] << endl;
}
Ans:-
int findMinVertex(vector<int> &distance, vector<int> &visited, int v) {
	int minVertex = -1;

	for(int i=0; i<v; i++) {
		if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])) minVertex = i;

	return minVertex;
}

void printShortestDistance(vector<vector<int>> &edges, int v){
	vector<int> distance(v, INT_MAX);
	vector<int> visited(v, false);
	distance[0] = 0;

	for(int i=0; i<v-1; i++) {
		int minVertex = findMinVertex(distance, visited, v);
		visited[minVertex] = true;
		for(int j=0; j<v; j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				int dist = distance[minVertex] + edges[minVertex][j];
				if(dist < distance[j]) {
					distance[j] = dist;
				}
			}
		}
	}

	for(int i=0; i<v; i++) cout << i << " " << distance[i] << endl;
}
*/ 