// set kth bit gfg question
// https://www.geeksforgeeks.org/problems/set-kth-bit3724/1

#include<iostream>
using namespace std;

class Solution{
public:
    int setKthBit(int N, int K)
    {
        return N | (1<<K);
    }
};

int main(){
    int num,k;
    cout<<"Enter the number: "<<endl;
    cin>>num;
    cout<<"Enter the value which bit of digit you set: "<<endl;
    cin>>k;
    Solution solution;
    int result = solution.setKthBit(num,k);
    cout<<"value of number after set bit: "<<result<<endl;
    return 0;
}

