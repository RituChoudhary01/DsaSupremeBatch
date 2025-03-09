/*Fancy Pattern #1
for 1<=n>=9
n=5
********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****

*/
#include<iostream>
#include<assert.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    // if(n>9){
    //     cout<<"Please Enter value <=9"<<endl;
    //     return 0;
    // }
    assert(n<=9);
    for(int row=0;row<n;row++){
     int startNumIndex = 8-row;
      int num = row+1;
     int countNum = num;
     for(int col = 0;col<17;col++){
        if(col==startNumIndex && countNum>0){
            cout<<num;
            startNumIndex+=2;
            countNum--;
        }
        else{
            cout<<"*";
        }
     }
     cout<<endl;
    }
}
