/*
Q1.Debug the code. BFS of a disconnected graph starting from 0.
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> output;
        vector<bool> visited(V, false);
				queue<int> q;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
		        int g_node = q.front();
            q.pop();
            output.push_back(g_node);
            for (auto it : adj[g_node]) {
		            if (!visited[it]) {
		                visited[it] = true;
                    q.push(it);
                }
            }
        }
        return output;
    }
};
Ans:-
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> output;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                queue<int> q;
                visited[i] = true;
                q.push(i);
                while (!q.empty()) {
                    int g_node = q.front();
                    q.pop();
                    output.push_back(g_node);
                    for (auto it : adj[g_node]) {
                        if (!visited[it]) {
                            visited[it] = true;
                            q.push(it);
                        }
                    }
                }
            }
        }
        return output;
    }
};

Q2.Debug the code. Find if path exists between source and destination.

class Solution {
public:
    bool dfs(int source , int destination , vector<int> adj[] , vector<int> &vis)
    {
        if(source == destination)
        {
            return true;
        }
        for(auto a:adj[source])
        {
            if(!vis[a])
            {
                if(dfs(a, destination, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]); 
            adj[edges[i][0]].push_back(edges[i][1]);            
        }
        return dfs(source , destination , adj , vis);
    }
};
Ans:-
class Solution {
public:
    bool dfs(int source , int destination , vector<int> adj[] , vector<int> &vis)
    {
        vis[source]=1;
        if(source==destination)
        {
            return true;
        }
        for(auto a:adj[source])
        {
            if(!vis[a])
            {
                if(dfs(a,destination , adj , vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]); 
            adj[edges[i][0]].push_back(edges[i][1]);            
        }
        return dfs(source , destination , adj , vis);
    }
};
Q3.Debug the code. Number of Connected Components.
vector<int> getOneComponent(bool** graph, int startingVertex, int v, bool* visited) {
	vector<int> component;
	queue<int> pendingNodes;
	pendingNodes.push(0);
	visited[0] = true;

	while(!pendingNodes.empty()){
		int current = pendingNodes.front();
		pendingNodes.pop();
		component.push_back(current);
		for(int i=0; i<v; i++){
			if(graph[current][i] && !visited[i]) {
				pendingNodes.push(i);
				visited[i] = true;
			}
		}

	}
	return component;
}

vector<vector<int>> getAllComponents(bool** graph, int v) {
	vector<vector<int>> result;
	bool* visited = new bool[v]();

	for(int i=0; i<v; i++){
		if(visited[i]){
			vector<int> component = getOneComponent(graph, i, v, visited);
			result.push_back(component);
		}
	}

	return result;
}
Ans:-
vector<int> getOneComponent(bool** graph, int startingVertex, int v, bool* visited) {
	vector<int> component;
	queue<int> pendingNodes;
	pendingNodes.push(startingVertex);
	visited[startingVertex] = true;

	while(!pendingNodes.empty()){
		int current = pendingNodes.front();
		pendingNodes.pop();
		component.push_back(current);
		for(int i=0; i<v; i++){
			if(graph[current][i] && !visited[i]) {
				pendingNodes.push(i);
				visited[i] = true;
			}
		}

	}
	return component;
}

vector<vector<int>> getAllComponents(bool** graph, int v) {
	vector<vector<int>> result;
	bool* visited = new bool[v]();

	for(int i=0; i<v; i++){
		if(!visited[i]){
			vector<int> component = getOneComponent(graph, i, v, visited);
			result.push_back(component);
		}
	}

	return result;
}


Q4.Debug the code. Return deep copy of the graph.
class Solution {
public:
    unordered_map<Node* , Node*> mp;
    
    Node* cloneGraph(Node* node) {
        
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node -> val, {});
            
            for(auto adj: node.neighbors)
            {
                mp[node].neighbors.push_back(cloneGraph(adj));
            }
        }
        
        return mp[node];
        
    }
};
Ans:-
class Solution {
public:
    unordered_map<Node* , Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
        {
            return NULL;
        }
        
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node -> val, {});
            
            for(auto adj: node -> neighbors)
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj));
            }
        }
        
        return mp[node];
        
    }
};
*/ 