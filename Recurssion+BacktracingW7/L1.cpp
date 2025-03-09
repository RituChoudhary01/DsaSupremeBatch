/*
Recursion:- When a function call itself.
when we apply Recursion:Jab kisi badi problem ka solution depend krta ho chhoti or same type ki problem par to Wha par recursion lg skta h.
Eg: 1.we find 2^5
  2^5 = 2*2^4
  bigger problem = 2* smaller problem
  f(n)=2*f(n-1);
2.find factorial
  Bigger problem = 5!
  5! = 5*4!
  bigger problem = 5* chotti problem
 3.n=5 we went to print counting in reverse order. 
 f(n) means print counting from n to 1
 f(5)=print count from 5 to 1
 f(5)=print(5)+f(4);
Main companant of RE(Recursive solution)
1.Base case(Rukna kab h)(mandatary part).
2.Recursive relation(mandatary part)
3.processing(optional part)
Head Recursion:jis code ke andar Recursive relation pahle aata ho processing se usko ham head recursion bolege.
1.Base case
2.Recursive relation
3.processing
Tail Recursion:jis code ke andar processing pahle aata ho Recursive relation se usko ham tail recursion bolege.
1.Base case
2.processing
3.Recursive relation
Magical line:- 1 case solve kardo baaki recursion sambhal lega.
*/ 

#include<iostream>
using namespace std;
// find factorial
int factorial(int n){
    //B.C. 
    if(n==1) return 1;
    // RE
    return n*factorial(n-1);
}
// print counting
void printCounting(int n){
    // BC
    if(n==0)
     return;
    //  RE
     printCounting(n-1);
    //  Processing
     cout<<n<<" ";
}
// print reverse counting
void printrevCounting(int n){
  // BC
    if(n==0)
     return;
      //  Processing
     cout<<n<<" ";
    //  RE
     printrevCounting(n-1);
}
 // fibonanacci series
  int fib(int n) {
    // BC
	if(n == 1) {
		//first term 
		return 0;
	}
	if(n == 2) {
		//second term
		return 1;
	}
    //RR -> f(n) = f(n-1) + f(n-2)
	int ans = fib(n-1) + fib(n-2);
	return ans;
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ans = factorial(n);
    cout<<"factorial of number  "<<n<<" is : "<<ans<<endl;

    cout<<"Printing counting from  1 to "<<n<<": ";
    printCounting(n);
    cout<<endl;
     cout<<"Printing reverse counting from  "<<n<<" to 1: ";
    printrevCounting(n);
    cout<<endl;
    cout<<n<<"th term of fibonanacci series is: "<<fib(n)<<endl;
    return 0;
}
