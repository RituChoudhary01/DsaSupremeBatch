// Stone Game
// https://leetcode.com/problems/stone-game/description/
#include<iostream>
#include<vector>
using namespace std;
bool stoneGame(vector<int>& piles){
    // there will be at least one way by which alice will win.that means,we should return true.
    // bcz problem is asking is there any way that alice can win.
    return true;
}
int main(){
    int n;
    vector<int>piles;
    cout<<"Enter size of piles vector: "<<endl;
    cin>>n;
    cout<<"Enter element of piles vector: "<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        piles.push_back(input);
    }
    cout<<stoneGame(piles);
    return 0;
}