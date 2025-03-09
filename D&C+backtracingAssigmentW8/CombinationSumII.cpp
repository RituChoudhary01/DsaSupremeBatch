//
//
#include <iostream>
#include <vector>
using namespace std;
void combinationSumHelper(vector<int> &candidates, int target, vector<int> &v, vector<vector<int> > &ans, int index)
{
    // BC
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    if (target < 0)
        return;

    for (int i = index; i < candidates.size(); i++)
    {
        if (i > index && candidates[i] == candidates[i - 1])
            continue;
        v.push_back(candidates[i]);
        combinationSumHelper(candidates, target - candidates[i], v, ans, i + 1);
        v.pop_back();
    }
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > ans;
    vector<int> v;
    combinationSumHelper(candidates, target, v, ans, 0);
    // set<vector<int> >st;
    // for(auto e:ans){
    //     st.insert(e);
    // }
    // ans.clear();
    // for(auto e:st){
    //     ans.push_back(e);
    // }
    return ans;
}
int main()
{
    int n, target;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    cin >> target;
    vector<vector<int> > ans = combinationSum2(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}