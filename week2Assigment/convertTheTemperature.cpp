// Q.Convert the temperature  Leetcode 2469.
// https://leetcode.com/problems/convert-the-temperature/description/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<double> convertTemperature(double celsius){
      double k = celsius+273.15;
      double f = celsius*1.80+32.00;
      vector<double>ans;
      ans.push_back(k);
      ans.push_back(f);
      return ans;  
    }
};

int main(){
    double celsius;
    cout<<"Enter the value of Temperature in celsius: "<<endl;
    cin>>celsius;
    Solution solution;
    vector<double> ans = solution.convertTemperature(celsius);
    cout<<"Value of temperature in Kelvin: "<<ans[0]<<endl;
    cout<<"Value of temperature in Fahrenheit: "<<ans[1]<<endl;
    return 0;
}