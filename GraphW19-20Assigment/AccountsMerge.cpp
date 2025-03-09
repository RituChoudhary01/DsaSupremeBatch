// Account Merge 
// https://leetcode.com/problems/accounts-merge/description/

#include <iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]); // Path compression
    }

    void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u != v) {
            if (rank[u] < rank[v]) {
                parent[u] = v;
            } else if (rank[u] > rank[v]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToAccount;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string& mail = accounts[i][j];
                if (emailToAccount.find(mail) == emailToAccount.end()) {
                    emailToAccount[mail] = i;
                } else {
                    unionSet(i, emailToAccount[mail], parent, rank);
                }
            }
        }

        unordered_map<int, set<string>> mergedAccounts;
        for (auto& it : emailToAccount) {
            int accountNo = findParent(parent, it.second);
            mergedAccounts[accountNo].insert(it.first);
        }

        vector<vector<string>> ans;
        for (auto& it : mergedAccounts) {
            int accountNo = it.first;
            vector<string> merged;
            merged.push_back(accounts[accountNo][0]); // Account name
            merged.insert(merged.end(), it.second.begin(), it.second.end()); // Emails
            ans.push_back(merged);
        }

        return ans;
    }

int main() {
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};

    vector<vector<string>> result = accountsMerge(accounts);

    cout << "Merged Accounts:\n";
    for (auto& acc : result) {
        for (auto& str : acc) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
