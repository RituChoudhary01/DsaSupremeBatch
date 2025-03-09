#include<iostream>
using namespace std;
void wavePrint(int arr[][4],int row,int col){
    for(int j=0;j<col;j++){
    if(j%2==0){
        for(int i=0;i<row;i++){
                cout<<arr[i][j]<<" ";
            }
     }
    else{
    for(int i=row-1;i>=0;i--){
        cout<<arr[i][j]<<" ";
            }
        }
    }
}

int main(){
    int arr[5][4]={{2,3,4,5},{6,7,8,9},{10,11,12,13},{12,11,13,14},{15,16,17,18}};
      wavePrint(arr,5,4);
}