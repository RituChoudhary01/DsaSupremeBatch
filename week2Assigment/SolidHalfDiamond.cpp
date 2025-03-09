// Solid Half Diamond
/*
n=5
*
**
***
****
*****
****
***
**
*
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number "<<endl;
    cin>>n;
    for(int row=0;row<2*n-1;row++){
       int cond=0;
       if(row<n){
        cond=row+1;
       }
       else{
        cond=2*n-row-1;
       }
            for(int col=0;col<cond;col++){
            cout<<"*";
        }
       
    cout<<endl;
    }
    return 0;

}