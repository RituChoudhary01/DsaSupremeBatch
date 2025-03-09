// Minimum number of removals to make mountain array
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute LIS or LDS and store sequence lengths
void solveOptimal(vector<int>& arr, vector<int>& lis) {
    if (arr.empty()) return;

    vector<int> ans;
    lis.resize(arr.size(), 1);

    for (int i = 0; i < arr.size(); i++) {
        auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
        int index = it - ans.begin();

        if (it == ans.end()) {
            ans.push_back(arr[i]);
        } else {
            *it = arr[i];
        }

        lis[i] = index + 1;
    }
}

// Function to find minimum removals for mountain array
int minimumMountainsRemovals(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return 0; 

    vector<int> lis, lds;
    solveOptimal(nums, lis); // Compute LIS
    reverse(nums.begin(), nums.end());
    solveOptimal(nums, lds); // Compute LDS
    reverse(nums.begin(), nums.end()); // Restore original order

    int largestMountains = 0;

    for (int i = 0; i < n; i++) {
        if (lis[i] > 1 && lds[n - i - 1] > 1) {
            largestMountains = max(largestMountains, lis[i] + lds[n - i - 1] - 1);
        }
    }

    return n - largestMountains; // Minimum removals to form mountain
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minimumMountainsRemovals(nums);
    cout << "Minimum removals to form a mountain array: " << result << endl;

    return 0;
}
