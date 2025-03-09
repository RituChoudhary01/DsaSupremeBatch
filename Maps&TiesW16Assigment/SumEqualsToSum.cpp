// Pairs of Equals Sum.
// https://www.geeksforgeeks.org/problems/sum-equals-to-sum4006/1

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool findPairs(long long a[],long long n){
    unordered_map<int,bool>mp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum = a[i]+a[j];
            if(mp.find(sum)!=mp.end()){
                return true;
            }
            else{
                mp[sum]=true;
            }
        }
    }
    return false;
}
int main(){
    long long a[7] ={3,4,7,1,2,9,8};
    bool ans = findPairs(a,7);
    cout<<"Find a Pairs of Equals Sum: "<<ans<<endl;
    return 0;
}