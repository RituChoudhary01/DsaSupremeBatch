#include<iostream>
using namespace std;
//Conditionals statements
/*
int main(){
 int score;
 cout<<"Enter the score"<<endl;
 cin>>score;
 if(score<300){
    cout<<"India wins"<<endl;
 }
//  cout<<"pak wins"<<endl;
// else statement
else{
    cout<<"pak wins"<<endl;
}

    int age;
    cout << "Enter the age " << endl;
    cin >> age;
    //if condition
    if(age >=18) {
     cout << "I can vote" << endl;
    }
    else {
     cout << "I cannot vote" << endl;
    }


 //if-elseif-else
    int marks;
    cout<<"Enter the marks: "<<endl;
    cin>>marks;
    if(marks >= 90) {
     cout << "A";
    }
    else if (marks >= 80){
     cout << "B";
    }
    else if(marks >= 60) {
     cout << "C";
    }
    else if(marks >= 40) {
     cout << "D";
    }
    else{
     cout << "F";
    }

//Loops
for(int i=0;i<5;i=i+1){
cout<<"Hellow ji"<<endl;
}

for(int i=0;i<5;i=i+1){
cout<<i<<endl;
}

for(int i=1;i<=10;i++){
cout<<2*i<<endl;
}

for(int index = 100;index>0;index = index/2){
cout<<index<<endl;
}

for(int i=5;(i>=0 && i<=10);i=i+1){
cout<<i<<endl;
}

int i=0;
for(; ; ){
if(i<5){
cout<<i<<endl;
i = i+1;
}
}

// HW Run the output of the following program

  if(cout<<"Hello ji"){
        cout<<"Kse ho sare"<<endl;
    }
   output:- Hello jiKse ho sare

  int n;
  if(cin>>n){
    cout<<"hello everyone";
  }
output:- print hello everyone  after taking input.

// pattern 
1.Solid rectangle

* * * * *
* * * * *
* * * * *
      //outer loop - row 
      for(int row=0; row<3; row=row+1) {
    // inner loop - col
      for(int col=0; col<5; col=col+1) {
        cout << "* ";
      }
      cout << endl;
     }

if n(given in input)
   int n;
   cout<<"Enter the value of n: "<<endl;
   cin>>n;
   for(int row = 0;row<n;row++){
    for(int col = 0;col<n;col++){
    cout<<"* ";
    }
    cout<<endl;
   }
2. Hollow rectangle
if row=4,col=7;
* * * * * * *
*           * 
*           *
* * * * * * *
int rowCount,colCount;
cin>>rowCount>>colCount;
for(int row = 0;row<rowCount;row = row+1){
// first and last row
 if(row==0||row==rowCount-1){
   for(int col=0;col<colCount;col=col+1){
   cout<<"* ";
   }
 }
 else{
//  first *
 cout<<"* ";
//  spaces
for(int space = 0;space=colCount-2;space=space+1){
cout<<" ";
}
// last *
cout<<"* ";
 }
 cout<<endl;
}


3.Half Pyramid
n=5
*
* *
* * *
* * * *
* * * * *

int n;
cin>>n;
for(int row = 1;row<=n;row++){
for(int col = 1;col<=row;col++){
cout<<"* ";
}
cout<<endl;
}

4.Inverted half Pyramid
n=4
* * * *
* * *
* *
*

int n;
cin>>n;
for(int row = 1;row<=n;row++){
for(int col = 1;col<=n-row+1;col=col+1){
cout<<"* ";
}
cout<<endl;
}

5.Numeric half pyramid
n=4
1
1 2
1 2 3
1 2 3 4

int n;
cin>>n;
for(int row=1;row<=n;row++){
for(int col = 1;col<=row;col++){
cout<<col<<" ";
}
cout<<endl;
}

6.Inverted half pyramid
n=4
1 2 3 4
1 2 3
1 2
1
int n;
cin>>n;
for(int row = 1;row <= n;row++){
for(int col=1;col<n-row;col++){
 cout<<col<<" ";
}
cout<<endl;
}
 return 0;
}
*/





