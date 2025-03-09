//  Spiral Matrix Leetcode 54.
// https://leetcode.com/problems/spiral-matrix/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       int leftCol = 0,rightCol = m-1;
       int topRow = 0,buttomRow = n-1;
       int size = 0;
       int totalSize = m*n;
       vector<int>ans;
       while(size<totalSize){
           for(int i=leftCol;i<=rightCol && size<totalSize;i++){
              ans.push_back(matrix[topRow][i]);
              size++;  
           }
           topRow++;
           for(int i=topRow;i<=buttomRow && size<totalSize;i++){
             ans.push_back(matrix[i][rightCol]);
             size++;
           }
           rightCol--;
           for(int i=rightCol;i>=leftCol && size<totalSize;i--){
            ans.push_back(matrix[buttomRow][i]);
            size++;
           }
           buttomRow--;
           for(int i=buttomRow;i>=topRow && size<totalSize;i--){
            ans.push_back(matrix[i][leftCol]);
            size++;
           }
            leftCol++;
       }
       return ans; 
        
    }
};

int main(){
    vector<vector<int> >matrix(3,vector<int>(3));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>matrix[i][j];
        }
    }
    Solution s;
   vector<int> ans  = s.spiralOrder(matrix);
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
   return 0;
}