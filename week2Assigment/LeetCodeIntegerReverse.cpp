/*
leetcode Q7.
// https://leetcode.com/problems/reverse-integer/description/
*/
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        unsigned n = abs(x);
        int ans = 0;
        while(n){
            int digit = n%10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10) return 0;
            ans = ans*10+digit;
            n=n/10;
        }
        if(x<0) return -ans;
        return ans;
        
    }
};
int main(){
    int num;
    cout<<"Enter the number : "<<endl;
    cin>>num;
     Solution solution;
    int result = solution.reverse(num);
    cout<<"reverse of "<<num<<" is :"<<result<<endl;
    return 0;
}
