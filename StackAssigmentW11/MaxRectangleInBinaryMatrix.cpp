// Maximal Rectangle
// https://leetcode.com/problems/maximal-rectangle/description/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the largest rectangle in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); 

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}


int maximalRectangle(vector<vector<char> >& matrix) {
    if (matrix.empty()) return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int> > v(n, vector<int>(m));

    // Convert char matrix to int matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = matrix[i][j] - '0';
        }
    }

    // Calculate max area row by row
    int area = largestRectangleArea(v[0]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j]) {
                v[i][j] += v[i - 1][j];
            } else {
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }

    return area;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<char> > matrix(n, vector<char>(m));
    cout << "Enter the binary matrix (0s and 1s only):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Maximal Rectangle Area: " << maximalRectangle(matrix) << endl;
    return 0;
}
