/*
Pointers:-
int a = 5;
memory me strage location ka pta shirf address se lga skte h.
cout<<a;
it means symbol table me a ka address stroge hoga and us address me a ka value store hoga.
& operator is used to find the address of a variable.
int a = 5;
cout<<a<<endl;
// show the address of a where 5 is stroge.
cout<<&a<<endl;

pointer
Pointer is a variable that stores the address of another variable.
int *ptr = &a;
where int is a data type.
* is a deference operator.
ptr is a pointer variable.
int* is a pointer to integer type.
char* is a pointer to character type.
Q. what is the size of pointer?
8bytes in 64 bit system. ans 4 bytes in 32 bit system.
Q.Why we need pointer?
1.For dynamic memory allocation.
2.for call by reference.
3.use for  memory management.

int *ptr;
is a bad practices.it access the garbage address which is not a part of our program.hence it show segment fault on compile time.

int *ptr = 0;
it is null pointer.
*/
#include<iostream>
using namespace std;
int main(){
  
        // int a = 5;
        // //pointer create
        // int* ptr = &a;

        // //access the value ptr is pointing to
        // cout << "Address of a is: " << &a << endl;
        // cout <<"value stored at ptr is: " << ptr << endl;
        // cout <<"value ptr is pointing to is: " << *ptr << endl;
        // cout << &ptr << endl;

        // int a = 5;
        // int* p = &a ;

        // cout <<sizeof(p) << endl;

        // char ch = 'b';
        // char* c = &ch ;

        // cout <<sizeof(c) << endl;

        // double dtr = 5.03;
        // double* d = &dtr ;

        // cout <<sizeof(d) << endl;

        //BAD PRACTICE
        // int* ptr;

        // cout << *ptr << endl;

        //NULL POINTER
        // int* ptr = 0;

        // cout << *ptr << endl;
        
        // int a = 5;

        // int* ptr = &a;

        // //copy pointer
        // int* dusraPtr = ptr;

        // cout << *ptr << endl;
        // cout << *dusraPtr << endl;
        int a = 10;
        int* p = &a;
        int* q = p;
        int* r = q;

        cout << a << endl; //10
        cout << &a << endl; //address of a 
        cout << p << endl; //address of a 
        cout << &p << endl; //address of p
        cout << *p << endl; //10
        cout << q << endl; //address of a
        cout << &q << endl; //address of q
        cout << *q << endl; //10
        cout << r << endl; //address of a
        cout << &r << endl; //address of r
        cout << *r << endl; //10
        cout << (*p + *q + *r) << endl; //30
        cout << (*p)*2 + (*r)*3 << endl; //50
        cout << (*p/2) - (*q)/2 << endl; //0
        return 0;
}