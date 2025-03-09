/*
Q1. What is time Complexity
    Amount of time taken by algorithm to run as a function of length of input.
Q2. Why to study T&S Complexity
     1.Good computer engineer always thinks about the complexity of the code written by him.
     2.Resources are limited.
     3.Measure algorithm to make efficient programs.
     4.Asked by interviewer after every solution you give.
 Q3.What is Space Complexity.
    1.Amount of space taken by an algorithm to run as a function of length of input.
     Ex. int n;
         cin>>n;
         int *b = new int[n];
    //Print b
         for(int i=0;i<n;i++){
         cout<<b[i];
         } 
         T.C =O(n) S.C = O(n)
Q4.Unit to Represent Complexity
   1.Big O:Upper Bound
   2.Theta :Average case
   3.Omega :Lower Bound.
Big O:Complexities
1.Contant time:O(1);
2.Linear time:O(n);
3.Logarithmic time:O(logn);
4.Quadratic time:O(n^2);
5.Cubic time:O(n^3);

Examples
1. f(n)=2n^2+3n   T.C:O(n^2);
2. f(n)=4n^4+3n^3  T.C:O(n^4);
3. f(n)=n^2+logn   T.C:O(n^2);
4. f(n)=234         T.C:O(1);
5.f(n) = O(n/4)     T.C:O(n);

O(1)< O(log n) < O(n^1/2) < O(n) < O(nlog n) < O(n^2) < O(n^3) < O(2^n) < O(n!) < O(n^n);
 Least Complexity ---------->  More Complexity --------->
linear search time complexity: O(n);
Binary search time complexity: O(logn);

Examples
1.
int main(){
int a=0,b=0,n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
cout<<"Hi\n";
}
for(int i=0;i<m;i++){
cout<<"Hi2";
}
return 0;
}
T.C:O(n)+O(m);
S.C:O(1);

2.
int main(){
int a=0,b=0,n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<"Hi\n";
}
}
for(int i=0;i<m;i++){
cout<<"Hi2";
}
return 0;
}

T.C:O(n^2)+O(m)
S.C:O(1);

3.
int main(){
int a=0,b=0,n,m;
cin>>n>>m;
for(int i=0;i<n;i++){
for(int j=n;i>=0;j--){
cout<<"Hi\n";
}
}
return 0;
}
T.C:O(n^2);
S.C:O(1);
*/