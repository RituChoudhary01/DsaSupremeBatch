// K Closest Points to Origin
// https://leetcode.com/problems/k-closest-points-to-origin/description/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Custom comparator for max heap
class myComp {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        int distA = a[0] * a[0] + a[1] * a[1];
        int distB = b[0] * b[0] + b[1] * b[1];
        return distA < distB;  // Max heap (we remove the farthest point)
    }
};

// Function to find k closest points to the origin
vector<vector<int> > kClosest(vector<vector<int> >& points, int k) {
    priority_queue<vector<int>, vector<vector<int> >, myComp> pq;

    for (auto& p : points) {
        pq.push(p);
        if (pq.size() > k) {
            pq.pop();  // Remove the farthest point if size exceeds k
        }
    }

    vector<vector<int> > ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main() {
    int row, k;
    cout << "Enter number of points: ";
    cin >> row;

    vector<vector<int> > points(row, vector<int>(2));
    cout << "Enter elements of points: \n";
    for (int i = 0; i < row; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    cout << "How many closest points to find: ";
    cin >> k;

    vector<vector<int> > ans = kClosest(points, k);

    cout << "The " << k << " closest points to origin are:\n";
    for (auto& i : ans) {
        cout << "[ " << i[0] << ", " << i[1] << " ]\n";
    }
    return 0;
}
