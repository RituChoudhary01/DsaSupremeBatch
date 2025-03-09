/*
Hollow Square pattern
n=4;
* * * *
*     *
*     *
* * * *
*/
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of pattern: "<<endl;
    cin>>n;
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
         if(row==0||row==n-1||col==0||col==n-1){
            cout<<"* ";
         } 
         else{
            cout<<"  ";
         }   
         
        }
        cout<<endl;
    }
    return 0;
}