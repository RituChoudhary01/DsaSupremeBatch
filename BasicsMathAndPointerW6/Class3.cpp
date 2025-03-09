/* Double pointer
int a = 5;
int *p = &a ->p is a pointer to int data.
int **q = &p ->q is a pointer to int* data.
*/

#include<iostream>
using namespace std;
void util(int* p){
     // p = p + 1;
    // *p = *p + 1;
}
void solve(int** ptr){
    // ptr = ptr+1;
    // *ptr = *ptr+1;
    **ptr = **ptr+2;
}
void solve(int& num){
    num = 50;
}
void solve(int* val){
    *val = *val+1;
}
// void solve(int*& p){
//     p = p+1;
// }
int main(){
 int a = 5;
 int *p = &a;
 int **q = &p;
 cout<<&a<<endl;
 cout<<a<<endl;
 cout<<p<<endl;
 cout<<&p<<endl;
 cout<<*p<<endl;
 cout<<q<<endl;
 cout<<&q<<endl;
 cout<<*q<<endl;
 cout<<**q<<endl;

 a = 5;
 p = &a;
 q = &p;
 cout<<"before"<<endl;
 cout<<a<<endl;
 cout<<p<<endl;
 cout<<*p<<endl;
//  function call
 util(p);
 cout<<endl<<"after"<<endl;
 cout<<a<<endl;
 cout<<p<<endl;
 cout<<*p<<endl;
 solve(q);
 cout<<a<<endl;

         a = 5;
        //creating a reference variable
        int& b = a;

        cout << a << endl;
        cout << b << endl;
        a++;
        cout << a << endl;
        cout << b << endl;
        b++;
        cout << a << endl;
        cout << b << endl;
         
         a = 5;
         solve(a);
         cout<<a<<endl;
         a = 12;
         p = &a;
         solve(p);
         cout<<a<<endl;
          a = 5;
         p = &a;
         cout<<"before"<<p<<endl;
         solve(p);
         cout<<"After"<<p<<endl;
     return 0;   
}