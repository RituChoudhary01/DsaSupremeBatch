/*
Q2. Fancy Patter #2
n=4
1
2*3
4*5*6
7*8*9*10
7*8*9*10
4*5*6
2*3
1
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count =1;
    // growing phase
    for(int row = 0;row<n;row++){
        for(int col = 0;col<=row;col++){
        cout<<count++;
          if(col!=row){
            cout<<"*";
          }
        }
        cout<<endl;
    }
        // shrinking phase
        int start = count-n;
        for(int row = 0;row<n;row++){
            int num = start;
        for(int col = 0;col<n-row;col++){
        cout<<num++;
          if(col!=n-row-1){
            cout<<"*";
          }
        }
         start = start-(n-row-1);
        cout<<endl;
    }
    return 0;
}