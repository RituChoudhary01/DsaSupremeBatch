/*Numeric Palindrome Equilateral Pyramid
n=5
     1
    121
   12321
  1234321
 123454321
 */
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int row=0;row<n;row++){
        // spaces
        for(int spaces=0;spaces<n-row;spaces++){
            cout<<" ";
        }
        int col = 0;
        for(;col<=row;col++){
            cout<<col+1;
        }
        col--;
        for(;col>0;col--){
            cout<<col;
        }
        cout<<endl;
    }
    return 0;
}