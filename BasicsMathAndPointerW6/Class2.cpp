/*
int arr[10];
arr is the base address of array;
arr[i]= &(arr+i);
i[arr]= &(i+arr);
arr[i]=i[arr]; both are equal.
arr,&arr,&aa[0] all are base address of array.We can access all the parts of the array through pointer.


difference b/w array and pointer
Array
 1. int arr[10];
 sizeof(arr)->total space taken by array here is 40.
 2. arr = arr+2 do not allow it show error by using this we try to change in symbol table.
Pointer
1.int *ptr = arr;
sizeof(ptr)->total space taken by pointer is 8 always for 64-bit system.
2.p=p+1 -> access to the next address 

char array
char ch[10]="ABCDEFGH";
char *p = ch;
cout<<p; The cout statement prints all the characters starting from the address stored in p until it encounters a null character (\0). This behavior is due to the specific implementation of cout for char arrays.

// bad practics
char *c = "hellow";
// good practics
char c[10]="hellow"
*/

#include <iostream>
using namespace std;
void solve(int arr[]) {
        cout <<"Size inside solve function " << sizeof(arr) << endl;
        cout <<"arr: " << arr << endl;
        cout << "&arr: " << & arr << endl;
        arr[0] = 50;
}

void update(int *p){
        cout << "Address stored inside p is: " << p << endl;
        cout << "Address of p  is:" << &p << endl;
        *p = *p + 10;
}

int main() {

        //int arr[4] = {12,44,66,18};

        // cout << arr << endl;
        // cout << arr[0] << endl;
        // cout << &arr << endl;
        // cout << &arr[0] << endl;

        // int* p = arr;
        // cout << p << endl;
        // cout << &p << endl;

        // cout << *arr << endl;
        // cout << arr[0] << endl;
        // cout << *arr + 1 << endl;
        // cout << *(arr) + 1 << endl;
        // cout << *(arr + 1) << endl;
        // cout << arr[1] << endl;
        // cout << *(arr + 2) << endl;
        // cout << arr[2] << endl;
        // cout << *(arr + 3) << endl;
        // cout << arr[3] << endl;

        // int i = 0;
        // cout << arr[i] << endl;
        // cout << i[arr] << endl;
        // cout << *(arr + i) << endl;
        // cout << *(i + arr) << endl;

        // give error
        //arr = arr + 2;

        // int* p = arr;
        // p = p + 2;

        // int arr[10];
        // cout << sizeof(arr) << endl;

        // int* p = arr;
        // cout << sizeof(p) << endl;

        // cout << sizeof(*p) << endl;

        // char ch[10] = "Babbar";
        // char* c = ch;

        // cout << ch << endl;
        // cout << &ch << endl;
        // cout << ch[0] << endl;

        // cout << &c << endl;
        // cout << *c << endl;
        // cout << c << endl;

        // char name[9] = "SherBano";
        // char* c = &name[0];

        // cout << name << endl;
        // cout << &name << endl;
        // cout << *(name + 3) << endl;
        // cout << c << endl;
        // cout << &c << endl;
        // cout << *(c + 3) << endl;
        // cout << c+2 << endl;
        // cout << *c << endl;
        // cout << c+8 << endl; 

        // char ch = 'k';
        // char* cptr = &ch;

        // cout << cptr << endl;

        // char name[10] = "babbar";
        // cout << name << endl;

        // char* c = "babbar";
        // cout << c << endl;


        // int arr[10] = {1,2,3,4};
        // cout << "Size inside main function. " << sizeof(arr) << endl;
        // cout << arr << endl;
        // cout << &arr << endl;

        // //printing array inside main
        // for(int i=0; i<10; i++) {
        // cout << arr[i] << " ";
        // }cout << endl;
        // cout << endl << endl << "Now calling solve function" << endl;

        // solve(arr);

        // cout << "Wapas main function me aagye h " << endl;

        // for(int i=0; i<10; i++) {
        //    cout << arr[i] << " ";
        // }
        // cout << endl;
        int a = 5;
        cout << "Address of a is: " << &a << endl;
        int* ptr = &a;
        cout << "address stored in ptr is: " << ptr << endl;
        cout << "Address of ptr is: " << &ptr << endl;
        update(ptr);
        cout<<"value of a is: " << a << endl;
        return 0;
}