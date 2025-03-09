// The Celebrity Problem
// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category[]=Stack&sortBy=
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int celebrity(vector<vector<int> > &M, int n) {
    stack<int> st;

    // Push all persons into the stack
    for (int i = 0; i < n; i++) {
        st.push(i);
    }

    // Find potential celebrity
    while (st.size() > 1) {  
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if (M[a][b] == 1) {
            // `a` knows `b`, so `a` is not a celebrity
            st.push(b);
        } else {
            // `a` does not know `b`, so `b` is not a celebrity
            st.push(a);
        }
    }

    // The remaining person might be a celebrity
    int mightBeCelebrity = st.top();
    st.pop();

    // Verify if the candidate is actually a celebrity
    for (int i = 0; i < n; i++) {
        if (i != mightBeCelebrity) {
            // Condition 1: Celebrity should not know anyone
            if (M[mightBeCelebrity][i] == 1) {
                return -1;
            }
            // Condition 2: Everyone should know the celebrity
            if (M[i][mightBeCelebrity] == 0) {
                return -1;
            }
        }
    }
    
    return mightBeCelebrity;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<vector<int> > M(n, vector<int>(n)); 
    cout << "Enter the matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    int ans = celebrity(M, n);
    if (ans == -1)
        cout << "No celebrity found.\n";
    else
        cout << "The celebrity is person: " << ans << endl;

    return 0;
}
