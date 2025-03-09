// 
#include<iostream>
#include<unordered_map>
using namespace std;

string isSubset(int a1[],int a2[],int n,int m){
    unordered_map<int,int>mp;
    string ans = "Yes";
    // map hasting using a1
    for(int i=0;i<n;i++){
        mp[a1[i]]++;
    }
    // check whether all elements of a2 present in a1
    for(int i=0;i<m;i++){
        if(mp.find(a2[i])==mp.end()){
            ans = "No";
            break;
        }
        else{
            if(mp[a2[i]]>0){
                mp[a2[i]]--;
            }
            else{
                ans = "No";
                break;
            }
        }
    }
    return ans;
}
int main(){
    int n=8;
    int arr1[8]={11,7,1,13,21,3,7,3};
    int m = 5;
    int arr2[5]={11,3,7,1,7};
    cout<<"Array Subset of another array: "<<isSubset(arr1,arr2,8,5);
    cout<<endl;
    return 0;
}