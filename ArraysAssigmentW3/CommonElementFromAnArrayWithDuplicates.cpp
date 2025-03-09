// Find common elements in three sorted arrays gfg
// https://www.geeksforgeeks.org/problems/common-elements1132/1
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
                if (ans.empty() || ans.back() != arr1[i]) {
                    ans.push_back(arr1[i]);
                }
                i++;
                j++;
                k++;
            } else if (arr1[i] < arr2[j]) {
                i++;
            } else if (arr2[j] < arr3[k]) {
                j++;
            } else {
                k++;
            }
        }
        if(ans.empty()) ans.push_back(-1); 
        return ans;
    }
};

int main() {
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;
    cout<<"Enter the size of first array:";
    int n;
    cin>>n;
    cout<<"Enter the element of first array: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    cout<<"Enter the size of second array:";
    int n1;
    cin>>n1;
    cout<<"Enter the element of second array: ";
    for(int i=0;i<n1;i++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }
    cout<<"Enter the size of third array:";
    int n2;
    cin>>n2;
    cout<<"Enter the element of third array: ";
    for(int i=0;i<n2;i++){
        int x;
        cin>>x;
        arr3.push_back(x);
    }
    
    Solution s;
    vector<int> ans = s.commonElements(arr1, arr2, arr3);
    
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
