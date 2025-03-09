// Car fleet
// https://leetcode.com/problems/car-fleet/description/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Car{
 public:
 int pos,speed;
 Car(int p,int s):pos(p),speed(s){}
};
static bool myComp(Car&a , Car&b){
    return a.pos<b.pos;
}
int carFleet(int target,vector<int>&position,vector<int>speed){
vector<Car>cars;
for(int i=0;i<position.size();i++){
    cars.push_back(Car(position[i], speed[i]));
}
sort(cars.begin(),cars.end(),myComp);
stack<float>st;
for(auto car:cars){
    float time = (target-car.pos)/((float)car.speed);
    while(!st.empty()&&time>=st.top()){
        st.pop();
    }
    st.push(time);
}
return st.size();
}
int main(){
    int target,n;
    cout<<"Enter the value of target "<<endl;
    cin>>target;
    cout<<"Enter the size of vector"<<endl;
    cin>>n;
    vector<int>position,speed;
    cout<<"Enter the element of position vector:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        position.push_back(input);
    }
    cout<<"Enter the element of speed vector:"<<endl;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        speed.push_back(input);
    }
    cout<<"Number of fleet forms at target: "<<carFleet(target,position,speed)<<endl;
    return 0;

}