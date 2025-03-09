/*
Pascal Triangle Pattern
n=5
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row = 1;row<=n;row++){
        int C = 1;
        for(int col = 1;col<=row;col++){
            cout<<C<<" ";
            C = C*(row-col)/col;
        }
        cout<<endl;
    }
    return 0;
}