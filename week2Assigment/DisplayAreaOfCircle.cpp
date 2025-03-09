/*
Write a function to find the area of circle.
*/
#include<iostream>
using namespace std;
 float circleArea(float radius){
    float area = 3.14*radius*radius;
    return area;
 }

int main(){

    int radius;
    cin>>radius;
    float area = circleArea(radius);
    cout<<"Area of circlr is: "<<area<<endl;
    return 0;
}