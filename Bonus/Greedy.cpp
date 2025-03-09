#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*
// Q1.Minimum Platforms
bool cmp(pair<int,int> a, pair<int,int> b) {
  return a.second < b.second;
}
int solve(int n, int arr[], int dept[]) {
  vector< pair<int, int> > data;
  for(int i=0; i<n; i++) {
    data.push_back({arr[i], dept[i]});
  }
  sort(data.begin(), data.end(), cmp);
  int cnt = 1;
  cout << data[0].first << ", "<< data[0].second << endl;
  int lastDept = data[0].second;
  for(int i=1; i<n; i++) {
    if(data[i].first >= lastDept) {
      //current train can be included
      cnt++;
      lastDept = data[i].second;
      cout << data[i].first << ", "<< data[i].second << endl;    }
  }
  return cnt;
}

int main() {
  int n = 4;
  int arr[] = {5,8,2,4};
  int dept[] = {7,11,6,5};

  int ans = solve(n, arr, dept) ;
  cout << "Answer is:  " << ans << endl;
  return 0;
}
*/
/*
// Q2.Shop in Candy Store
int main() {
  int prices[] = {2,8,6,9,4,7};
  int n = 6;

  //algo starts here
  sort(prices, prices + n);

  int amount = 0;
  int buy = 0;
  int free = n-1;

  while(buy <= free) {
    amount += prices[buy];
    buy++;
    free--;
    free--;
  }
  cout << "asnwer is " << amount << endl;
  return 0;
}
*/

/*
// Q3.DEFKIN Defense of a Kingdom
// https://www.spoj.com/problems/DEFKIN/

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  int t = n;
  vector<int> rowC;
  vector<int> colC;

  rowC.push_back(0);
  colC.push_back(0);

  while(t--) {
    int a, b;
    cin >> a >> b;
    rowC.push_back(a);
    colC.push_back(b);
  }
  //size of 2D grid
  rowC.push_back(x+1);
  colC.push_back(y+1);
  sort(rowC.begin(), rowC.end());
  sort(colC.begin(), colC.end());
  int maxLen = INT_MIN;
  for(int i=1; i<rowC.size(); i++) {
      int a = rowC[i-1];
      int b = rowC[i];

      maxLen = max(maxLen, b-a-1);
  }
  int maxWidth = INT_MIN;
  for(int i=1; i<colC.size(); i++) {
      int a = colC[i-1];
      int b = colC[i];
      maxWidth = max(maxWidth, b-a-1);
  }
  cout << "answer is " << maxLen * maxWidth << endl;
  return 0;
}
*/
/*
// Q4. Minimum Cost 
int main() {
  int arr[] = {4,3,2,6};
  int n = 4;
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i=0; i<n; i++) {
    pq.push(arr[i]);
  }
  int cost = 0;
  while(pq.size() != 1) {
    int first = pq.top();
    pq.pop();
    int second = pq.top();
    pq.pop();

    cost += first + second;
    int newLength = first + second;
    pq.push(newLength);

  }
  cout << "Cost is: " << cost << endl;
  return 0;
}
*/
/*
// Q5. 0 - 1 Knapsack Problem
bool cmp(pair<int,int> a, pair<int,int> b) {
  double ratio1 = ((1.0)*a.first) / a.second;
  double ratio2 = ((1.0)*b.first) / b.second;
  return ratio1 > ratio2;
}

int main() {
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int n= 3;
  int capacity = 50;

  vector<pair<int,int> > data;
  for(int i=0; i<n; i++) {
    data.push_back(make_pair(val[i], wt[i]));
  }

  sort(data.begin(), data.end(), cmp);
  int totalValue = 0;

  for(int i=0;i<n; i++) {
    pair<int,int> item = data[i];
    int itemValue = item.first;
    int itemWeight = item.second;
    if(itemWeight <= capacity) {
      //add kardo value ko
      totalValue += itemValue;
      //update krdo capacity ko
      capacity = capacity - itemWeight;
    }
    else {
      //fraction include krdo
      //update value
      double ratio = ((1.0)*itemValue) / itemWeight;
      int valueToAdd = ratio * capacity;
      totalValue += valueToAdd;

      //udpate capacity;
      capacity = 0;
    }
  }
  cout << "Answer is: "<< totalValue << endl;
  return 0;
}
*/
// Q6.Distribution of Cholate among m student
int main() {
  int n = 7;
  int m = 3;
  int arr[] = {7,3,2,4,9,12,56};
  //sort
  sort(arr, arr + n);

  //check differences in m-size window
  int i = 0;
  int j = m-1;
  int diff = INT_MAX;
  while(j<n) {
    int newDiff = arr[j] - arr[i];
    diff = min(diff, newDiff);
    j++;
    i++;
  } 
  cout << "Answer is: " << diff << endl;
  return 0;
}