#include<iostream>
using namespace std;
// Write a function to add 2 number
int getSum(int a,int b){
    return a+b;
}

// Find max of three number
int maxNumFun(int num1,int num2,int num3){
    if(num1>=num2){
        if(num1>=num3) return num1;
        else return num3;
    }
    else{
        if(num2>=num3) return num2;
        else return num3;
    }
}

// Counting from 1 to N
void printCounting(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
}
// Write a Function of Students and Grade Problem
char getGrade(int marks){
	// if(marks >= 90) 
	// 	return 'A';
	// else if(marks >= 80)
	// 	return 'B';
	// else if(marks >= 70)
	// 	return 'C';
	// else if(marks >= 60) 
	// 	return 'D';
	// else
	// 	return 'E';

	//assuming marks is between 0 to 100
	switch(marks/10){
		case 10 : return 'A'; break;
		case 9  : return 'A'; break;
		case 8  : return 'B'; break;
		case 7  : return 'C'; break;
		case 6  : return 'D'; break;
		default: return 'E';
	}
}
// By using cout statement show how function work
int getEvenSum(int n) {
	cout << "inside getEvenSum Function" << endl;
	cout << "Value of n is " << n << endl;
	
	int sum = 0 ;
	cout << "Initial value of sum is " << sum << endl;
	for(int i = 2; i<=n; i = i + 2) {
		cout << "for value of i: " << i << endl;
		sum = sum + i;
		cout << "sum now become: " << sum << endl;
	}
	cout << "returning sum = " << sum << endl;
	return sum;
}
int main(){
// function problem statement
// function call stack
// Pass by value concept

// Q1.Write a function to add 2 number
   int num1,num2;
   cin>>num1>>num2;
   int sum = getSum(num1,num2);
   cout<<getSum(num1,num2)<<endl;
   cout<<sum<<endl;

// Q2.Find max of three number
  int maxNum1,maxNum2,maxNum3;
  cout<<"Enter the three number: "<<endl;
  cin>>maxNum1>>maxNum2>>maxNum3;
  cout<<" maximum of "<<maxNum1<<", "<<maxNum2<<", "<<maxNum3<<" : "
  <<maxNumFun(maxNum1,maxNum2,maxNum3)<<endl;

// Q3. Counting from 1 to N
   int countNum;
   cout<<"Enter the number "<<endl;
   cin>>countNum;
   printCounting(countNum);

//    Q4.Write a Function of Students and Grade Problem
     int marks;
	cout << "Enter the marks: " << endl;
	cin >> marks;

	char finalGrade = getGrade(marks);
	cout << finalGrade << endl;

	for(int i=0; i<=100; i++) {
		char ans = getGrade(i);
		cout << "Grade for marks = " << i << " is " << ans << endl;
	}

    // Q5. Sum of even number upto N.
    int n;
	cout << "Enter the value of n " << endl;
	cin >> n;

	cout << "Calling getEvenSum function " << endl;
	int ans = getEvenSum(n);
	cout << "Even sum is  " << ans << endl;
  return 0;
}
