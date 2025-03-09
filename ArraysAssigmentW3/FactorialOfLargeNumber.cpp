// Factorials of large numbers gfg problem
//https://www.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1

#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution{
 public:
    vector<int> factorial(int n){
        vector<int> ans;
        ans.push_back(1);
        int carry = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < ans.size(); j++) {
                int x = ans[j] * i + carry;
                ans[j] = x % 10;    
                carry = x / 10;    
            }
            while (carry) {
                ans.push_back(carry % 10);
                carry /= 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number to find the factorial: " << endl;
    cin >> n;
    Solution s;
    vector<int> ans = s.factorial(n);
    cout << "Factorial of " << n << " is: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

