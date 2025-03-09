#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
Bitwise operation:- 
1.Bitwise AND(&);
2.Bitwise OR(|);
3.Bitwise XOR(^);
4.Bitwise NOT(~);
5.Right Shift(>>);
6.Left Shift(<<);
*/
// Q.check given number is even or odd
void checkEven(int n){
    if(n&1)
     cout<<"odd"<<endl;
     else cout<<"Even"<<endl;
}
// Q.Get ith bit of a number
int getithBit(int n,int i){
int mask = 1<<i;
int ans = n&mask;
if(ans==0) return 0;
else return 1;
}
// Q.set ith bit of a number
void setithBit(int n,int i){
    int mask = 1<<i;
    int ans = n|mask;
    cout << "after setting: " << ans << endl;
}
// Q.Clear ith bit of a number
void clearIthBit(int n,int i){
    int mask = ~(1<<i);
    n = n&mask;
    cout << "aster clearing " << n << endl; 
}
//Q.Check Power of 2
bool checkPowerOf2(int n){
    if((n&(n-1))==0) return true;
    else return false;
}
//Q. update ith set bit
void updateIthBit(int n,int i,int target){
    clearIthBit(n,i);
    int mask = target<<i;
    n = n|mask;
      cout << "after updating " << n << endl;
}
//Q. clear last i bits
void clearLastIBits(int n,int i){
    int mask = (-1<<i);
    n = n&mask;
    cout << "after clearing last i bits: " << n << endl;
}
// Q.count set bits
int countSetBits(int n){
    int count = 0;
    while(n!=0){
        int lastBit = n&1;
        if(lastBit) count++;
        n = n>>1;
    }
    return count;
}
// Q. count set bits fast way
int countSetBitsFast(int n){
    int count = 0;
    while(n!=0){
        n = (n&(n-1));
        count++;
    }
    return count;
}
// Q.Clear bits in range
void clearBitsInRange(int n,int i,int j){
    int a = (-1<<(i+1));
    int b = (1<<j)-1;
    int mask = a|b;
    n = n&mask;
    cout<<"after clearing in range "<<n<<endl;
}
// Fast Exponention
long long fastExpo(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b & 1) { 
            result *= a;
        }
        a *= a;  
        b >>= 1; 
    }
    return result;
}
// Single Number
// https://leetcode.com/problems/single-number/
int singleNumber(int nums[],int n) {
        int ans = 0;
       for(int i=0;i<n;i++){
          ans = ans^nums[i];  
       } 
       return ans;
    }
// find all subsequences of a string
void getSubsequences(string str){
    vector<string>ans;
    int n = str.length();
    for(int num = 0;num<(1<<n);num++){
        string temp = "";
         //we will create subsequence string in this temp string
        for(int i=0;i<n;i++){
            char ch = str[i];
            if(num&(1<<i)){
                 //non-zero value k liye , include current character
                temp.push_back(ch);
            }
        }
      if(temp.length() >= 0){
      //store in ans
      ans.push_back(temp);
    }
}
sort(ans.begin(), ans.end());
  cout << "Count of subsequences " << ans.size() << endl;
  cout << "printing the subsequences" << endl;
  for(auto i: ans) {
    cout << i << endl;
  }
}
int main(){
   checkEven(50);
   cout<<getithBit(10, 1)<<endl;
   setithBit(10,2);
   clearIthBit(23, 4);
   clearLastIBits(7, 2);
   cout << "Power of 2 ans: " << checkPowerOf2(45) << endl;
   cout << "Number of set bits: " << countSetBitsFast(743) << endl;
   clearBitsInRange(15,3,0);
   string str = "abc";
   getSubsequences(str);
   cout<<"Fast Exponention: "<<fastExpo(2,5)<<endl;
   int arr[]={2,2,1,3,4,4,3};
   cout<<"Single Number Present in array: "<<singleNumber(arr,7)<<endl;
   return 0;
}