// Minimum Number of Refueling Points
// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minRefuelStop(int target,int startFuel,vector<vector<int> >&stations){
    int stops = 0;
    int dist = 0;
    int i=0;
    int fuel = startFuel;
    priority_queue<pair<int,int> >pq;
    while(true){
        while(i<stations.size()){
            // push stations within the reach with my current fuel levels from my current pos
            if(stations[i][0]<=dist+fuel)
            pq.push(make_pair(stations[i][1],stations[i][0]));
            else break;
            i++;
        }
        // travel with full fuel level
        dist+=fuel;
        fuel = 0;
        // reached
        if(dist >= target) break;
        // no fuel station within reach
        if(pq.empty()){
            stops = -1;
            break;
        }
        // refuel ans re-adjust dist & fuel based on the distance trave
        auto &top = pq.top();
        fuel = (dist-top.second)+top.first;
        dist = top.second;
        pq.pop();
        stops++;
    }
    return stops;
}
int main(){
    int target,startFuel;
    cout<<"Enter the target Distance "<<endl;
    cin>>target;
    cout<<"Enter the value of start Fuel in car: "<<endl;
    cin>>startFuel;
    int row,col;
    cout<<"Enter number of stations: "<<endl;
    cin>>row;
    vector<vector<int> >stations(row,vector<int>(2));
    cout<<"Enter Element of grid: "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<2;j++){
            cin>>stations[i][j];
        }
    }
    cout<<"Minimum Number of Refueling Point: "<<minRefuelStop(target,startFuel,stations)<<endl;
    return 0;
}
