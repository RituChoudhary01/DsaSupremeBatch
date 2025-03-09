#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
#include<map>
using namespace std;
// Q1.Number of Provinces.
// https://leetcode.com/problems/number-of-provinces/

 void dfs(unordered_map<int,bool>& vis, int src, vector<vector<int>>& isConnected) {
        //cout << "received a call for src: " << src << endl;
        vis[src] = true;
        //row -> src
        //col -> we will write a loop
        int size = isConnected[src].size();
        for(int col=0; col<size; col++) {
            if(src != col && isConnected[src][col] == 1) {
                //col is a nbr
                if(!vis[col] ) {
                    dfs(vis,col, isConnected);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count = 0;
        int n = isConnected.size();
        //i represents nodes here
        for(int i=0; i< n; i++)  {
            if(!visited[i]) {
                //cout << "calling for src: "<< i << endl;
                dfs(visited, i, isConnected);
                count++;
            }
        }
        return count;
    }
    // Q2.Number of Islands
    // https://leetcode.com/problems/number-of-islands/description/
    void bfs(map< pair<int,int> , bool >& visited, int row, int col, vector<vector<char> >& grid){
        queue<pair<int,int> > q;
        //initial steps
        q.push({row,col});
        visited[{row,col}] = true;

        while(!q.empty()) {
            pair<int,int> fNode = q.front();
            q.pop();
            int x = fNode.first;
            int y = fNode.second;

            //i can move in 4 directions
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if( newX >=0 && newX < grid.size() && newY>=0 && newY < grid[0].size() &&
                    !visited[{newX, newY}] && grid[newX][newY] == '1') {
                        q.push({newX, newY});
                        visited[{newX, newY}] = true;
                }

            } 
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        map< pair<int,int> , bool > visited;
        int count = 0;
        for(int row=0; row<grid.size(); row++) {
            int n = grid[row].size();
            for(int col=0; col<n; col++) {
                if(!visited[{row,col}] && grid[row][col] == '1') {
                    bfs(visited, row, col,grid);
                    count++;
                }
            }
        }
        return count;
    }
    // Q3.Flood Fill
    // https://leetcode.com/problems/flood-fill/description/
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int,int>, bool>& vis,vector<vector<int> >& arr ) {

        vis[{x,y}] = true;
        arr[x][y] = newColor;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if(newX>=0 && newX<arr.size() && newY>=0 && newY<arr[0].size()&&
                !vis[{newX, newY}]  && arr[newX][newY]==oldColor) {
                    dfs(newX, newY, oldColor, newColor, vis, arr);   
                }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        map<pair<int,int>, bool> vis;
        vector<vector<int>> ans = image;
        dfs(sr,sc,oldColor,color,vis,ans);
        return ans;
    }

    // Q4.Rotting Oranges
    // https://leetcode.com/problems/rotting-oranges/description/
    
       int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int> , int > > q;
        vector<vector<int>> arr = grid;
        int count = 0;
        int ansTime = 0;
        //insert all rotten oranges in queue
        for(int row=0; row<grid.size(); row++) {
            for(int col=0; col<grid[row].size(); col++ ) {
                if(grid[row][col] ==2) {
                    //rotten orange found
                    pair<int,int> coordinate = make_pair(row, col);
                    q.push({coordinate,0});
                }
            }
        }
            while(!q.empty()) {
            pair<pair<int,int> , int > fNode = q.front();
            q.pop();
            int x = fNode.first.first;
            int y = fNode.first.second;
            int time = fNode.second;

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >=0 && newX < arr.size() && newY >=0 && newY < arr[0].size() &&
                 arr[newX][newY] == 1) {
                     pair<int,int> newCoordinates = make_pair(newX, newY);
                     ansTime = max(ansTime, time+1);
                     q.push({newCoordinates, time + 1});
                     //mark rotten
                     arr[newX][newY] = 2;
                 }
            }
         }

        //check for fresh orange
        for(int i=0;i<arr.size(); i++) {
            for(int j=0;j<arr[0].size();j++) {
                if(arr[i][j] == 1) {
                    return -1;
                }
            }
        }
       return ansTime;
      }