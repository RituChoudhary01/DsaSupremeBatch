// Lecture 2 Notes.
/*
What is programming language?
  A language using which we can instruct the computer to carry out real life tasks and computation is called a programming language.

  HLL  ---->  compiler  ----->  Machine understandable format
  c++ source  Layer                    [0,1]
  code

  c++ data types and variables
   c++ data types
    1.Built-in/primitive
      a. Integer
        1.int
        2.char
      b. floating
        1.float
        2.double
      c. void
    2.Derived data type
      a.arrays
      b.pointer
      c.references
    3.User-defined data type
      a.structure
      b.unions
      c.classes
      d.enumeration

    Q. positive VS negative integer
        MSB of -ve number is 1 and MSB of +ve number is 0.
    Q.How negative number stroge in memory
      stroge in 2's compliment form.
        first find 1's complement of a number
        then add 1;

    EX. a = -7;
    step1:ignore the negative sign and write equivalent binary number
    7-->00000000000000000000000000000111
    step2: 2's complement
      1's complement:- 11111111111111111111111111111000 
                       +                              1
                      -----------------------------------
                       11111111111111111111111111111001

    Q.Signed VS unsigned int
     An int is signed by default, meaning it can represent both positive and negative values. An unsigned is an integer that can never be negative it can only be zero or positive.
    TypeCasting
       1.Implicit type casting
       2.Explicit type casting
    Operators:
      1.Arithmetic: %,+,-,*,/;
      2.Relational: <=,=>,!=,==,<,>.
      3.Assignment: =
      4.Logical: &&,||,!
      5.Bitwise: &,|,~,^
*/
#include<iostream>
using namespace std;

int main(){
    int num = 5;
    char ch = 's';
    double d = 12.45;
    bool flag = true;
    string name = "dsa";
    long long longnum = 234789002;
    cout<<num<<endl;
    cout<<flag<<endl;
    cout<<longnum<<endl;

    cout<<"size of integer: "<<sizeof(num)<<endl;
    cout<<"size of charter: "<<sizeof(ch)<<endl;
    cout<<"size of double: "<<sizeof(d)<<endl;
    cout<<"size of boolean: "<<sizeof(flag)<<endl;
    cout<<"size of string: "<<sizeof(name)<<endl;
    cout<<"size of long long: "<<sizeof(longnum)<<endl;


     cout <<  "Namaste Bharat\n" << endl ;
     cout << '\n';
     cout<<"Enter the number:"<<endl;
     int number1;
     //taking input
     cin >> number1;
     cout << "You entered " << number1<< endl;

    int a = 5;
    int b = 3;
    cout << !(a==5)<<endl;
    
     cout << a+b << endl;
     cout << a-b << endl;
     cout << a*b << endl;
     cout << a%b << endl;
     cout << a/b << endl;
     cout<< (a==b) << endl;
     cout<< (a!=b) <<endl;
     cout<< (a>b) <<endl;
     cout<< (a<b) <<endl;
     cout<< (a<=b) <<endl;
     cout<< (a>=b) <<endl;
     cout<< (a&&b) <<endl;
     cout<< (a||b) <<endl;
     cout<< (!a) <<endl;
     cout<< (!b) <<endl;
     cout<< (!0) <<endl;
     cout<< (!-987) <<endl;
     cout<< (a&b) <<endl;
     cout<< (a|b) <<endl;
     cout<< (a^b) <<endl;
      cout<<(~a) <<endl;
     cout<< (~b) <<endl;
      cout<< (~0) <<endl;
       cout<< (~-6) <<endl;

     
    //  typecasting
    char cha = 'p';
    int num2 = cha;
    cout<<num2<<endl;
    int x = (int)d ;
    cout << "value of x is " << x << endl;
    cout << (5)/((double)3);

}