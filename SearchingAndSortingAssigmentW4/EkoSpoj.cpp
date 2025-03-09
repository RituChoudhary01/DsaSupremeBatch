//Eko spoj
//https://www.spoj.com/problems/EKO/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossibleSolution(vector<long long int> trees,long long int m,long long int mid){
    long long int woodCollected = 0;
    for(long long int i = 0;i<trees.size();i++){
        if(trees[i]>mid){
            woodCollected+=trees[i]-mid;
        }
    }
    return woodCollected>=m;
}
long long int maxSawBladeHeight(vector<long long int>trees, long long int m){
    long long int start = 0,ans = -1;
    int end = *max_element(trees.begin(),trees.end());
    while(start <= end){
        long long int mid = start+(end-start)/2;
        if(isPossibleSolution(trees,m,mid)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}
int main(){
    long long int n,k;
    cin>>n>>k;
    vector<long long int>trees;
    for(long long int i=0;i<n;i++){
        int num;
        cin>>num;
        trees.push_back(num);
    }
    int ans = maxSawBladeHeight(trees,k);
    cout<<ans<<endl;
    return 0;
}