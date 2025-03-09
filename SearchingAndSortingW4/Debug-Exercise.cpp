/*
Q1.Debug the code.This code is implementation for binary search.
#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left){
        int mid = (left + right)/2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            binarySearch(arr, left, mid - 1, x);
        else
            binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    return 0;
}
Ans:-
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2; //fix: use this formula to avoid overflow
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x); //fix: add return statement
        else
            return binarySearch(arr, mid + 1, right, x); //fix: add return statement
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    return 0;
}


Q2.Debug the code. This code is implementation for binary search for calculating ceil index. The ceil index is the index of the smallest element in the array that is greater than or equal to a given target value.

int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else 
            ceil = mid;
            right = mid - 1;
    }

    return ceil;
}
Ans:-
int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
}

Q3.Debug the code. This code tries to implement Selection Sort.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[j];
        arr[j] = temp;
    }
}
Ans:-
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];  // fix: swap with min element, not current element
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

Q4.Debug the code. This code tries to implement Bubble Sort.

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
Ans:-
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) { // fix: i < n-1 instead of i <= n
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
*/