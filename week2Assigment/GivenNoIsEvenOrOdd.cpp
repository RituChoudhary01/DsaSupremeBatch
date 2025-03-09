// write a function to check given number is even or odd
#include<iostream>
using namespace std;
bool checkEven(int n){
    if(n%2 == 0) return true;
    else{
        return false;
    }
}

int main(){
int n;
cin>>n;
bool isEven = checkEven(n);
if(isEven){
    cout<<n<<" isEven number."<<endl;
}
else{
    cout<<n<<" is odd number."<<endl;
}
return 0;
}