/*
Q1.What is vector?
  Linear data structure
  dynamic array

 Q2. Declare
   vector<int>arr;
   vector<int>arr{10,20,30};
   vector<int>arr(10,-1);
   vector<int>arr(n);
    // to add element in vector
    arr.push_back(5);
    arr.push_back(6);
   //to remove element for vector from back; 
     arr.pop_back();
   //to find the size of vector(no.of element)
    arr.size();
  //to find the capacity of vector (how many element it can store);
    arr.capacity();
  //how to acces nth element in vector
 */

#include<iostream>
#include<vector>
using namespace std;
int findUnique(vector<int> arr){
  int ans = 0;
  for(int i=0;i<arr.size();i++){
    ans = ans^arr[i];
  }
  return ans;
}
void rotateByOne(vector<int>arr){
  int temp = arr[0];
  for(int i=1;i<arr.size();i++){
    arr[i-1]=arr[i];
  }
  arr[arr.size()-1]= temp;
}

int majorityElement(vector<int>arr){
  int count = 1;
  int ans = arr[0];
  for(int i=1;i<arr.size();i++){
    if(arr[i]==ans){
      count++;
    }
    else{
      count--;
    }
    if(count==0){
      ans = arr[i];
      count = 1;
    }
  }
  count = 0;
  for(int i=0;i<arr.size();i++){
    if(arr[i]==ans){
      count++;
    }
  }
  if(count>arr.size()/2){
    return ans;
  }
  else return -1;
}

int main(){
//Q1.Find Unique Element every element present twice except one element 
int n;
cin>>n; 
vector<int> arr(n);
cout << "Enter the elements " << endl;
//taking input
for(int i=0; i<arr.size(); i++){
		cin >> arr[i];
}
int uniqueElement = findUnique(arr);
cout << "Unique Element is: " << uniqueElement << endl;

// Q2.Union of 2 vector if we have given distinct element in both vector
int arr[] = {1,3,5,7,9};
	int sizea = 5;
int brr[] = {2,4,6,8};
	int sizeb = 4;
vector<int> ans;

	//push all element of vector arr
	for(int i=0; i<sizea; i++) {
		ans.push_back(arr[i]);
	}

	//push all element of vector brr
	for(int i=0; i<sizeb; i++) {
		ans.push_back(brr[i]);
	}

	//print ans
	cout << "Printing ans array " << endl;
	for(int i=0; i<ans.size(); i++) {
		cout << ans[i] << " " ;
	}

// Q3.Intersection of 2 vector
  vector<int> arr3{1,2,3,3,4,6,8};
	vector<int> brr3{3,3,4,10};
  vector<int> ans ;
  //outer loop on arr vector
	for(int i=0; i<arr3.size(); i++){
		int element = arr3[i];
		// for every element, run loop on brr
		for(int j=0; j<brr3.size(); j++) {
			if(element == brr3[j]) {
				//mark 
				brr3[j] = -1;
				ans.push_back(element);
			}
		}
	}
 //print ans 
	for(auto value: ans) {
		cout << value << " ";
	}
 cout << endl;
// Q4.pair sum(find a pair that upto addition gives value equal to sum)
  arr={10,20,40,60,70};
	int sum = 80;
  //print all pairs
	//outer loop will traverse for each element
	for(int i=0; i<arr.size(); i++){
		int element = arr[i] ;
  //for every element, will traverse all next elements
		for(int j=i+1; j<arr.size(); j++) {
			if(element + arr[j] == sum ){
				cout << "Pair Found " << element <<"," << arr[j] << endl;
			}
		}
}
// Q5.find a triplet that upto addition gives value equal to sum
  arr={10,20,30,40};
	int sum = 80;
   for(int i=0; i<arr.size(); i++) {
		int element1 = arr[i];
   for(int j=i+1; j<arr.size(); j++) {
			int element2 = arr[j];
   for(int k=j+1; k<arr.size(); k++) {
				int element3 = arr[k];
    if(element1 + element2 + element3 == sum) {
					cout << element1 <<","<< element2 <<","<< element3 << endl;
				}
			}
		}
	}
// Q6.Sort 0's and 1's
  arr = {0,1,0,1,1,0,1,0,1,1};
	int start = 0;
	int end = arr.size() -1;
  while( start < end) {
		if(arr[start] == 0) {
			start++;
		}
		else if(arr[end]== 1) {
			end--;
		}
    else{
      swap(arr[start],arr[end]);
      start++;
      end--;
    }
	}
 //print
	for(auto val : arr) {
		cout << val << " ";
	}

// H.W
// Q1.Left rotate an array by 1 element
arr={2,3,4,5,6,7,8};
rotateByOne(arr);
for(auto val:arr){
  cout<<val<<" ";
}

// Q2.Majority element in an array
arr={2,2,2,3,2,3,3,2,5,5,4,3,2,2,2};
int maj = majorityElement(arr);
if(maj==-1){
  cout<<"No majority elment"<<endl;
}
else{
 cout<<"Majority element is: "<<maj<<endl;
}
// Q3.Buy and sell stock Leetcode problem 121.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
int prices[]={7,1,5,3,6,4};
int size = 6;
int maxProfit = 0;
int bestBuyPrice = prices[0];
for(int i=1;i<size;i++){
  if(prices[i]>bestBuyPrice){
    maxProfit = max(maxProfit,prices[i]-bestBuyPrice);
  }
  bestBuyPrice = min(bestBuyPrice,prices[i]);
}
return maxProfit;
}