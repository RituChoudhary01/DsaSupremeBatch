#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
using namespace std;

// Q1.Course Schedule
// https://leetcode.com/problems/course-schedule/description/

bool topoSortBfs(int n, unordered_map<int,list<int> >& adjList){
    vector<int> ans;
    queue<int> q;
    unordered_map<int, int> indegree;
   //indegree calculate
    for(auto i: adjList ) {
      int src = i.first;
      for(auto nbr:i.second) {
        indegree[nbr]++;
      }
    }
    //put all nodes inside queue, which has indegree = 0
    for(int i=0; i<n; i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
    }
     //bfs logic
    while(!q.empty()) {
      int fNode = q.front();
      q.pop();
      ans.push_back(fNode);
      //or we can do count++
        for(auto nbr: adjList[fNode]) {
        indegree[nbr]--;
        //check for zero again
        if(indegree[nbr] == 0) {
          q.push(nbr);
        } 
      }
      
    }
    if(ans.size() == n) {
    //valid topo sort
      return true;
    }
    else {
      //invalid
      return false;
    }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;
        //build adjacency list
        for(auto task: prerequisites) {
          int u = task[0];
          int v = task[1];
          adjList[v].push_back(u);
        }

        bool ans = topoSortBfs(numCourses, adjList);
        return ans;
    }
    // Q2.Course Schedule II
    // https://leetcode.com/problems/course-schedule-ii/description/

    vector<int> topoSortBfs1(int n, unordered_map<int,list<int> >& adjList) {
    vector<int> ans;
    queue<int> q;
    unordered_map<int, int> indegree;

    //indegree calculate
    for(auto i: adjList ) {
      int src = i.first;
      for(auto nbr:i.second) {
        indegree[nbr]++;
      }
    }

    //put all nodes inside queue, which has indegree=0
    for(int i=0; i<n; i++) {
      if(indegree[i] == 0) {
        q.push(i);
      }
    }

    //bfs logic
    while(!q.empty()) {
      int fNode = q.front();
      q.pop();

      ans.push_back(fNode);
      //or we can do count++

      for(auto nbr: adjList[fNode]) {
        indegree[nbr]--;
        //check for zero again
        if(indegree[nbr] == 0) {
          q.push(nbr);
        } 
      }
    }

    if(ans.size() == n) {
      //valid topo sort
      return ans;
    }
    else {
      //invalid
      return {};
    }
    
  }
       vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int> > adjList;
        //build adjacency list
        for(auto task: prerequisites) {
          int u = task[0];
          int v = task[1];
          adjList[v].push_back(u);
        }
         vector<int> ans = topoSortBfs1(numCourses, adjList);
        return ans;
    }

    // Q3.Word Ladder
    // https://leetcode.com/problems/word-ladder/description/

     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int> > q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end()) ;
        //jo bhi word queue me insert karunge, toh usko set me se remove krdunge
        st.erase(beginWord);
        while(!q.empty()) {
            pair<string,int> fNode = q.front();
            q.pop();
            string currString = fNode.first;
            int currCount = fNode.second;

            //check kahin destination tak toh nahi pohoch gye
            if(currString == endWord) 
                return currCount;
            
            for(int index=0; index<currString.length(); index++) {
                //hr index pr jo value h, usko main 'a' to 'z' se replace karunga
                char originalCharacter = currString[index];
                for(char ch='a'; ch<='z'; ch++) {
                    currString[index] = ch;
                    //check in wordList
                    if(st.find(currString) != st.end()) {
                        q.push({currString, currCount + 1});
                        st.erase(currString);
                    }
                }
                //bringing back the currString to its original State
                currString[index] = originalCharacter;
            }
        }
        return 0;
        }

    // Q4.Path with Minimum effort
    // https://leetcode.com/problems/path-with-minimum-effort/description/
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
        vector<vector<int> > dist(heights.size(), vector<int>(heights[0].size(), INT_MAX));
        pq.push({0, {0,0}});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto fNode = pq.top();
            pq.pop();
            int frontNodeDifference = fNode.first;
            int x = fNode.second.first;
            int y = fNode.second.second;

            //check ans tak toh nahi pahuch agye
            if(x == heights.size() - 1 && y == heights[0].size() - 1) {
                return dist[x][y];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >=0 && newY >=0 && newX <heights.size() && newY < heights[0].size()) {
                    int currDifference = abs(heights[x][y] - heights[newX][newY]);
                    int newMax = max(frontNodeDifference, currDifference);
                    if(newMax < dist[newX][newY]) {
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }