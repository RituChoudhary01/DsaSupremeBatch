// Car Fleet II
// https://leetcode.com/problems/car-fleet-ii/description/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int> > &cars) {
    int n = cars.size();
    vector<double> answer(n, -1); 
    stack<int> st; 
    for (int i = n - 1; i >= 0; i--) {
        // Remove cars that are moving faster and ahead of current car
        while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
            st.pop();
        }

        // Check for valid collisions
        while (!st.empty()) {
            double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

            // If the car in stack collides after it has already collided with another, ignore it
            if (answer[st.top()] == -1 || colTime <= answer[st.top()]) {
                answer[i] = colTime;
                break;
            }
      // Otherwise, pop and check next car
            st.pop();
        }
        st.push(i);
    }

    return answer;
}

int main() {
     int n;
    cout << "Enter the number of cars: ";
    cin >> n;

    vector<vector<int> > cars(n, vector<int>(2));

    cout << "Enter the position and speed of each car: \n";
    for (int i = 0; i < n; i++) {
        cin >> cars[i][0] >> cars[i][1]; 
    }

    vector<double> result = getCollisionTimes(cars);
    for (double time : result) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}
