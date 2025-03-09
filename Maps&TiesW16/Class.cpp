/*
HashMap (Hash Table)
A HashMap is a data structure that stores elements in key-value pairs. It allows fast insertion, deletion, and searching using a hash function.

Time Complexity of HashMap Operations:
Data Structure	                Time Complexity
Ordered Map (map)	            O(log n) (Implemented using Red-Black Tree)
Unordered Map (unordered_map)	O(1)(Average Case,Implemented using Hash Table)
Example of HashMap:
Key (string)	Value (int)
"Scorpio"	     9
"Fortuner"	     10
"Innova"	     3
How HashMap Works?
1. Hash Function
A hash function converts a key into an integer index where the value is stored in an array.
A good hash function should be:

Efficient
Uniformly distribute keys
Minimize collisions
2. Hash Code
A hash code is a numerical representation of the key.

3. Compression Function
A compression function maps the hash code into a valid array index.

Handling Collisions
When two keys hash to the same index, we need a method to handle this collision. There are different techniques:

1. Open Addressing
Linear Probing: If a collision occurs, check the next available slot sequentially.
Quadratic Probing: Instead of checking sequentially, check at an increasing interval (1², 2², 3², ...).
Cubic Probing: Similar to quadratic probing but checks at intervals of 1³, 2³, 3³, ....
2. Chaining
Store multiple elements in the same index using a linked list.
Load Factor
The load factor determines when the HashMap should resize to maintain efficiency.

Load Factor = The load factor determines when the HashMap should resize to maintain efficiency.  
Load Factor= n/b;

Where:
n = Number of elements in the HashMap.
b = Number of available slots (buckets).

Good Load Factor
A good load factor is < 0.7, meaning less than 70% of the table is occupied.
If the load factor exceeds this threshold, rehashing is performed (i.e., resizing the hash table).

Advantages of HashMap
Fast Insertion, Deletion, and Searching in O(1) (Average case).
Efficient memory utilization when load factor is maintained.
Flexible and supports dynamic resizing when needed.

Disadvantages of HashMap
Collisions can degrade performance to O(n).
Memory overhead due to hash function and extra storage.
Unordered storage (for unordered_map in C++).
*/ 

#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    // creation
    unordered_map<string,int>m;
    // insertion
    pair<string,int>p=make_pair("scorpio",9);
    m.insert(p);
    pair<string,int>p2("alto",2);
    m.insert(p2);
    m["fortuner"] = 10;
    // acces
    cout<<m.at("alto")<<endl;
    cout<<m.at("scorpio")<<endl;
     cout<<m["fortuner"]<<endl;
    //  seach in map
    cout<<m.count("Scopio")<<endl;
    if(m.find("fortuner")!=m.end()){
        cout<<"fortuner is find"<<endl;
    }
    cout<<m.size()<<endl;
    cout<<m["hummer"]<<endl;
    cout<<m.size()<<endl;
    cout<<"printing all entries: "<<endl;
    for(auto i:m){
        cout<<i.first<<" -> "<<i.second<<endl;
    }
    // count freq of each char
    string str = "thiruvananthapuram";
    unordered_map<char,int>freq;
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        freq[ch]++;
    }
    for(auto i:freq){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

