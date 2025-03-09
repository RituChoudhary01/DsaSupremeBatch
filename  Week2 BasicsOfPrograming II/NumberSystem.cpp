#include<iostream>
using namespace std;
int decimalToBinary(int n){
    int binaryno = 0;
    int i=0;
    while(n>0){
        int bit = n%2;
       binaryno = bit*pow(10,i++)+binaryno;
        n/=2;
    }
    return binaryno;
}

int decimalToBinaryMethod2(int n){
    // Bitwise Method.
    int binaryno = 0;
    int i=0;
    while(n>0){
        int bit = (n&1);
        binaryno = bit*pow(10,i++)+binaryno;
        n = n>>1;
    }
    return binaryno;
}

int binaryToDecimal(int n){
    int decimal = 0;
     int i=0;
     while(n){
        int bit = n&1;
        decimal = decimal+bit*pow(2,i++);
        n = n/10;
     }
    return decimal;
}

int binaryToDecimalMethod2(int n){
    int decimal = 0;
    int i=0;
    while(n){
        int bit = n%2;
        decimal = decimal+bit*pow(2,i++);
        n = n/10;
    }
    return decimal;
}
int main(){
    /*  Number System:- 1.Method to represent numeric values or quantities using different digits.
     Decimal System:-
     1.The decimal number system has base 10.
     2.It uses digits from 0 to 9.
     3.Base:it is the number of symbols(digits) a number system uses.
     Binary Number System
     1.Number system using base 2.
     2.It uses two digits i.e.,0 and 1.

     Decimal to Binary Conversion
     Division Method
     1.Divide number by 2.
     2.store reminder.
     3.Repeat above steps with the Quotient until quotient is less than 2.
     4.Reverse the bits so obtained.
    Bitwise Method
    1.Obtain bit with bitwise AND operation i.e. (N&1).
    2.Right Shift N by 1.(N=N>>1).
    3.Repeat above steps till N>0.
    4.Reverse the bits so obtained.

    Binary to Decimal Conversion
    1.Multiple each digit with its place value.
    2.Add up all place values.
    3.Sum is the Decimal number.
    */
    int n;
    cout<<"Enter the decimal number to convert into binary: "<<endl;
    cin>>n;
    int binary = decimalToBinary(n); 
    cout<<binary<<endl;
    int binary1 = decimalToBinaryMethod2(n);
    cout<<binary1<<endl;
    int n1;
    cout<<"Enter the binary number to convert into decimal: "<<endl;
    cin>>n1;
    int decimal = binaryToDecimal(n1);
    cout<<decimal<<endl;
    int decimal1 = binaryToDecimalMethod2(n1);
    cout<<decimal1<<endl;
    return 0;
}