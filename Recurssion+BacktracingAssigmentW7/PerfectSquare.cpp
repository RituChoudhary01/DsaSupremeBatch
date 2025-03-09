// Perfect Squares
//https://leetcode.com/problems/perfect-squares/description/
#include<iostream>
using namespace std;
int numSquareHealper(int n){
    if(n==0) return 1;
    if(n<0) return 0;
    int ans = INT_MAX;
    int i=1;
    int end = sqrt(n);
    while(i<=end){
        int prefectSquare = i*i;
        int numberOfPerfectSquare = 1+numSquareHealper(n-prefectSquare);
        if(numberOfPerfectSquare<ans){
            ans = numberOfPerfectSquare;
        }
        i++;
    }
    return ans;

}
int numSquare(int n){
    return numSquareHealper(n)-1;
}
