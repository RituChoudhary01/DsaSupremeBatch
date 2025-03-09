#include<iostream>
using namespace std;
/* Q1. 
int main(){
    float f = 10.5;
    float p = 2.5;
    float* ptr =&f;
    (*ptr)++;
    *ptr = p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl;
}
// output:-2.5 2.5 2.5
*/
/*
Q2.
int main(){
  int a = 7;
  int b = 17;
  int*c = &b;
  *c = 7;
  cout<<a<<" "<<b<<endl;  
}
otput:7 7
*/
/*
Q3.
int main(){
    int *ptr = 0;
    int a = 10;
    *ptr = a;
    cout<<*ptr<<endl;
}
Output: Error 
*/
/*
Q4.Which of the following gives the memory address of variable 'b' pointed by pointer 'a' i.e.
int b =10;
int *a = &b;
ans : a;
*/
/*
Q5.
int main(){
    char ch ='a';
    char* ptr = &ch;
    ch++;
    cout<< *ptr<<endl;
}
// output:b
*/

/*
Q6.

int main(){
    int a = 7;
    int* c = &a;
    c = c + 1;
    cout<<a<<" "<<*c<<endl;
}
// output 7 garbage value
*/
/*
Q7.Assume the memory address of variable 'a' is 400 ant integer takes 4 bytes ,what will be the output-
int a = 7;
int *c = &a;
c = c+3;
cout<<c<<endl;
Ans : c = 400+3*4 = 412
*/
/*
Q8.Assume memory address of variable 'a' is:200 and a double variable is of size 8 bytes,what will be the output-
double a = 10.54;
double *d = &a;
d = d+1;
cout<<d<<endl;
ans: 200+8 = 208;
*/
/*
Q9.Assume integer takes 4 bytes and integer pointer 8 bytes.
int a[5];
int *c;
cout<<sizeof(a)<<" "<<sizeof(c);
ans:20 8
*/
/*
Q10.
int main(){
    int a[]={1,2,3,4};
    cout<<*(a)<<" "<<*(a+1);
    }
    // output:1 2
    */
   /*
   Q11.Assume that address of 0th index of array 'a' is:200.What is the output-
   int a[3]={1,2,3};
   cout<<*(a+2);
   ans:3
   */
/*
Q12.
int main(){
    int a[]={1,2,3,4};
    int* p = a++;
    cout<< *p <<endl;
}
output:error try to change in symbol table using a++;
*/
/*
Q13.
int main(){
    int arr[]={4,5,6,7};
    int* p = (arr+1);
    cout<<*arr+9;
    return 0;
}
// output:13
*/
/*
Q14.Assume address of 0th index of array 'b' is 200.What is the output-
char b[] = "xyz";
char *c = &b[0];
cout<<c<<endl;
output:xyz
*/
/*
Q15.
int main(){
    char s[]="hello";
    char *p = s;
    cout<<s[0]<<" "<<p[0];
    return 0;
}
// output: h h
*/
/*
Q16.
int main(){
    char arr[20];
    int i;
    for(i=0;i<10;i++){
        *(arr+i) = 65+i;
    }
    *(arr+i)='\0';
    cout<<arr;
    return 0;
}
//output:ABCDEFGHIJ
*/
/*
Q17.
int main(){
    char *ptr;
    char str[]="abcdefg";
    ptr = str;
    ptr+=5;
    cout<<ptr;
}
// output:fg
*/
/*
Q18.
int main(){
    int numbers[5];
    int *p;
    p = numbers;
    *p = 10;
    p = &numbers[2];
    *p = 20;
    p--;
    *p = 30;
    p = numbers+3;
    *p = 40;
    p = numbers;
    *(p+4) = 50;
    for(int n = 0;n<5;n++){
        cout<<numbers[n]<<" ";
    }
    return 0;
}
// output:10 30 20 40 50
*/
/*
Q19.
int main(){
    char st[]="ABCD";
    for(int i=0;st[i]!='\0';i++){
        cout<<st[i]<<*(st)+i<<*(i+st)<<i[st];
    }
}
// output:A65AAB66BBC67CCD68DD
*/
/*
Q.20
int main(){
    float arr[5]={12.5,10.0,13.5,90.5,0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1+3;
    cout<<*ptr2<<" ";
    cout<<ptr2-ptr1;
    return 0;
    }
    // output:90.5 3
*/
/*
Q21.
    void changeSign(int *p){
        *p = (*p)* -1;
    }
    int main(){
        int a = 10;
        changeSign(&a);
        cout<<a<<endl;
        return 0;
    }
    // output: -10
*/
/*
Q22.
void fun(int a[]){
    cout<<a[0]<<" ";
}
int main(){
    int a[]={1,2,3,4};
    fun(a+1);
    cout<<a[0];
}
// output 2 1
*/
/*
Q23.
void square(int *p){
    int a = 10;
    p = &a;
    *p = (*p)*(*p);
}
int main(){
    int a = 10;
    square(&a);
    cout<<a<<endl;
}
// output 10
*/
/*
Q.24
void Q(int z){
    z+=z;
    cout<<z<<" ";
}
void p(int *y){
    int x = *y+2;
    Q(x);
    *y = x-1;
    cout<<x<<" ";
    }
    int main(){
        int x = 5;
        p(&x);
        cout<<x;
        return 0;
    }
    // output 14 7 6
*/
/*
Q25.
int main(){
    int a = 10;
    int *p = &a;
    int **q = &p;
    int b = 20;
    *q = &b;
    (*p)++;
    cout<<a<<" "<<b<<endl;
}
// output:10 21
*/
/*
Q26.
int f(int x,int *py,int** ppz){
    int y,z;
    **ppz+=1;
    z = **ppz;
    *py+=2;
    y = *py;
    x+=3;
    return x+y+z;
}
int main(){
    int c,*b,**a;
    c = 4;
    b = &c;
    a = &b;
    cout<<f(c,b,a);
    return 0;
}
// output:19
*/
/*
Q27.
int main(){
    int ***r ,**q,*p,i=8;
    p = &i;
    (*p)++;
    q =&p;
    (**q)++;
    r = &q;
    cout<<*p<<" "<<**q<<" "<<***r;
    return 0;
}
// output 10 10 10
*/
/*
Q28.*/
void increment(int **p){
    (**p)++;
}
int main(){
    int num = 10;
    int *ptr = &num;
    increment(&ptr);
    cout<<num<<endl;
}
// output 11