/*
2D arrays
int arr[3][2];
we visualize in 2D array but in merory it is stored in 1D array.

row = 3;
column = 2;
Total element = row*col;
3*2 = 6;
row lies inbetween 0 to 2;
column lies inbetween 0 to 1;
visualize in 2D array formula is index = i * col + j;
where i is the row index. and j is the column index.

2D vector
vector of vector
//declare 2D vector
vector<vector<int>>v;
outer vector<inner vector<data type>>name of vector;

vector<vector<int>>arr(row,vector<int>(col,-1));

vector<vector<int>>arr(5,vector<int>(5,23));
*/

#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

void print2DArrayRowWiseSum(int arr[][4],int row,int col){
    for(int i=0;i<row;i++){
        int sum = 0;
        for(int j=0;j<col;j++){
            sum+=arr[i][j];
        }
        cout<<"sum of row "<<i<<" is: "<<sum<<endl;
    }
}

void print2DArrayColumnWiseSum(int arr[][4],int row,int col){
    for(int i=0;i<col;i++){
        int sum = 0;
        for(int j=0;j<row;j++){
            sum+=arr[j][i];
        }
        cout<<"sum of column "<<i<<" is: "<<sum<<endl; 
    }
}

pair<int,int>linearSearch2Dmatrix(int arr[][4],int row,int col,int target){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==target){
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

pair<int,int> minMaxOfMatrix(int arr[][3],int row,int col){
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            mini = min(mini,arr[i][j]);
            maxi = max(maxi,arr[i][j]);
        }
    }
    return make_pair(mini,maxi);
}


int main(){
// declare 2D array
int arr[3][3];
// initialize 2D array
int brr[3][3] = {{2,3,4},{34,43,2},{-87,34,-54}};
// row wise print
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
    cout<<brr[i][j]<<" ";
}
cout<<endl;
}

// column wise print
cout<<"Printing column wise"<<endl;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){
    cout<<brr[j][i]<<" ";
}
cout<<endl;
}
// Q1.print row wise sum
int arr1[5][4];
for(int row = 0;row<5;row++){
    for(int col=0;col<4;col++){
        cin>>arr1[row][col];
    }
}
cout<<"Printing row wise sum"<<endl;
print2DArrayRowWiseSum(arr1,5,4);

// Q2.print column wise sum
int arr2[4][4];
for(int row = 0;row<4;row++){
    for(int col=0;col<4;col++){
        cin>>arr2[row][col];
    }
}
cout<<"Printing column wise sum"<<endl;
print2DArrayColumnWiseSum(arr2,4,4);


// Q3.linear search in 2D matrix
int arr3[3][4]={{2,4,6,67},
                 {23,-45,65,3},
                 {23,-101,3,4}};
   int key = -101;
  pair<int,int> ans = linearSearch2Dmatrix(arr3,3,4,key);
  if(ans.first == -1 || ans.second == -1){
    cout<<"Key not found"<<endl;
  }               
  else{
    cout<<"First occurence of key is found at row:"<<ans.first<<" and column: "<<ans.second<<endl;
  }

// Q4.min and max element in 2D matrix
int arr4[3][3]={{2,3,4},
                {34,-99,34},
                {23,456,67}};
pair<int,int> ans1 = minMaxOfMatrix(arr4,3,3);
cout<<"Minimum element is: "<<ans1.first<<endl;
cout<<"Maximum element is: "<<ans1.second<<endl;

// Q5.Transpose of martix
int arr5[4][4]={{2,53,24,5},
                {61,27,8,99},
                {13,14,15,23},
                {93,45,6,89}};
    cout<<"Transpose of matrix is:"<<endl;
    // transpose of matrix
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            swap(arr5[i][j],arr5[j][i]);
        }
    }
    // print transpose matrix
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<arr5[i][j]<<" ";
        }
        cout<<endl;
    }            
return 0;
}
