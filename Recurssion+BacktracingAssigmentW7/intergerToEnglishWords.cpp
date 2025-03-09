//Integer to English Words 
//https://leetcode.com/problems/integer-to-english-words/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, string>> mp = {
    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"},{90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"},{40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"},{17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"},{12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"},
    {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};

string numberToWords(int num) {
    if (num == 0) {
        return "Zero";
    }

    string result = "";
    for (int i = 0; i < mp.size(); i++) { // Using a traditional for loop
        if (num >= mp[i].first) {
            string prefix = "";
            if (num >= 100) {
                prefix = numberToWords(num / mp[i].first) + " ";
            }
            string word = mp[i].second;
            string suffix = (num % mp[i].first != 0) ? " " + numberToWords(num % mp[i].first) : "";

            return prefix + word + suffix;
        }
    }
    return "";
}

int main() {
    int n;
    cin >> n;
    cout << numberToWords(n) << endl;
    return 0;
}
