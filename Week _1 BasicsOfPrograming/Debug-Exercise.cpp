#include<iostream>
using namespace std;
/*
Q1.The below code snippet has some errors. Let’s debug it and make it compile & run successfully.

void main() {
	int i=0;
	i=i+1;
	cout<<i:
	/*print i \* //i=i+1
    //comment in not correct format
	cout<<++i;
}

Q2.Below code should print the sum of ‘i’ and ‘j’.

void main() {
	short i=2300, j=4322;
	cout>>"i+j=">>-(i+j);
    // count line is incorrect 
    cout<<"i+j"<<(i+j);
}

Q3.Find perimeter of a rectangle.
void main() {
	float l, b;
	P = 2(l+b);
	printf("Perimeter=", P);
}
ans:- float P = 2*(l+b);
printf("Perimeter=%f",P);

Q4.Print solid square pattern.
void main(){
	int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++i) {
            cout<<"*\n";
        }
        cout<<endl;
    }
}
Ans:- for(int j=0;j<n;j++){
cout<<"*";
}

Q5.Check given number is Prime or not.

int main(){
	int n;
	cin >> n;
	bool isPrime = true;
  for(int i=2;i<n;i++){
      if(i%n == 0){
          isPrime = false; 
          break;
      }
  }
	if(isPrime){
		cout<<"Prime"<<endl;	
	}
	else{
		cout<<"Not Prime"<<endl;	
	}
  return 0;
}

Ans:- if(n%i==0) make this line correct

Q6.Print Numeric Hollow Inverted Half Pyramid.
void main(){
    int n;
    cin>>n;
    for(int i=0;i<n;++i{
    for(int j=j+1;j<=n;j++){
    if(j==i+1 || j == n - i - 1 || i == 0){
    cout<<j;
    }
    else{
     cout<<" ";
            }
        }
        cout<<endl;
    }
}

Ans:-for(int j=i+1;j<=n;j++){
if(j==i+1 || j == n || i == 0)

Q7.Print following pattern.
         1
       2 3 2
     3 4 5 4 3
   4 5 6 7 6 5 4
 5 6 7 8 9 8 7 6 5

 int main() {
  int n;
  std::cin>>n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n - i - 1; j++) {
      printf("  ");
    }
    for (int j = i; j < i; j++) {
      printf("%d ", j);
    }
    int ele = 2 * (n - i - 1);
    for (int j = 1; j <= i - 1; j++) {
      printf("%d ", ele--);
    }
    printf("\n");
  }
  return 0;
}

Ans:--

int main(){
  int n;
  std::cin>>n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n - i; j++) {
      printf("  ");
    }
    for (int j = i; j < 2 * i; j++) {
      printf("%d ", j);
    }
    int ele = 2 * (i - 1);
    for (int j = 1; j <= i - 1; j++) {
      printf("%d ", ele--);
    }
    printf("\n");
  }
  return 0;
}


Q8.Print hollow full pyramid pattern.

 void main(){
 int n;
 cin>>n;
 for (int i=0; i<n; ++i{
 for (int j=0; j<n*2-1; ++j){
	int k=0;
    if(j<n-i-1){
    cout<<" ";
    }
    else if(k < 2*i+1){
    if(k==0 || k == 2*i - 1 || i == n - 1){
    cout<<"*";
    }
    else{
    cout<<" ";
    }
    }
    else{
    cout<<" ";
    } k++;
    }
    cout<<endl;
    }
}

Ans:

void main(){
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
    int k=0;
    for (int j=0; j<n*2-1; ++j) {
    if(j<n-i-1){
        cout<<" ";
    }
    else if(k < 2*i+1){
    if(k==0 || k == 2*i || i == n - 1){
      cout<<"*";
    }
    else{
       cout<<" ";
    }
      k++;
    }
    else{
        cout<<" ";
    }
    }
    cout<<endl;
    }
}
*/