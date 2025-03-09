/*
 Hollow full pyramid
 n=4.
    *
   ***
  *****
 *******
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        int k=0;
        for(int j=0;j<(2*n-1);j++){
            if(j<n-row-1)
            cout<<" ";
            else if(k<2*row+1){
              if(k==0||k==2*row||row==n-1)
              cout<<"*";
              else
             cout<<" ";
             k++;
         }
        else
        cout<<" ";
         }
    cout<<endl;
       }
    return 0;
}