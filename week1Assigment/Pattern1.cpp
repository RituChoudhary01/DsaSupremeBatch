/*
Solid Square Pattern
n = 4
* * * * 
* * * *
* * * *
* * * *
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of patter: "<<endl;
     cin>>n;
     for(int row = 0;row<n;row++){
     for(int col = 0;col<n;col++){
        cout<<"* ";
     }
     cout<<endl;
     }
}