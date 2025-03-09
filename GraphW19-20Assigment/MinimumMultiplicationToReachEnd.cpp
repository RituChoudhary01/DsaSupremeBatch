// Minimum Multiplications to reach End
// https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/0
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0; // Already at target

        queue<pair<int, int> > q;
        const int mod = 100000;
        vector<int> dist(100000, -1); // Distance array
        dist[start] = 0;
        q.push({start, 0});

        while (!q.empty()) {
            auto [front, steps] = q.front();
            q.pop();

            for (auto it : arr) {
                int newNode = (front * it) % mod;

                if (newNode == end) return steps + 1; // Reached the target

                if (dist[newNode] == -1) { // Unvisited
                    dist[newNode] = steps + 1;
                    q.push({newNode, steps + 1});
                }
            }
        }
        return -1; // If unreachable
    }
};

int main() {
    Solution obj;
    vector<int> arr = {2, 3, 5};
    int start = 3, end = 30;
    
    int result = obj.minimumMultiplications(arr, start, end);
    cout << "Minimum multiplications required: " << result << endl;
    
    return 0;
}
