//Prata spoj   
// https://www.spoj.com/problems/PRATA/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPossibleSolution(vector<int>cooksRanks,int nP,int mid){
    int currP = 0;
    for(int i=0;i<cooksRanks.size();i++){
        int R = cooksRanks[i],j=1;
        int timeTaken = 0;
        while(true){
            if(timeTaken += R <= mid){
                ++currP;
                timeTaken += j*R;
                ++j;
            }
            else{
                break;
            }
        }
        if(currP >= nP) return true;
    }
return false;
}
int minTimeToComplate(vector<int>cooksRanks,int nP){
  int start = 0;
  int highestRank = *max_element(cooksRanks.begin(),cooksRanks.end());
  int end = highestRank*(nP*(nP+1)/2);
  int ans = -1;
  while(start <= end){
    int mid = (start+end)/2;
    if(isPossibleSolution(cooksRanks,nP,mid)){
        ans = mid;
        end = mid-1;
    }
    else{
        start = mid-1;
    }
  }
  return ans;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int nP,nC;
        cin>>nP>>nC;
        vector<int> cooksRanks;
        while(nC--){
            int R;
            cin>>R;
            cooksRanks.push_back(R);
        }
        int ans = minTimeToComplate(cooksRanks,nP);
        cout<<ans<<endl;
    }
    return 0;
}