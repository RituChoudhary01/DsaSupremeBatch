// N-Stacks in an array
#include <iostream>
using namespace std;

class Nstack {
    int *a, *top, *next;
    int n;     // Number of stacks
    int size;  // Size of the main array
    int freeSpot;  // Points to the next available free index

public:
    // Constructor
    Nstack(int _n, int _s) : n(_n), size(_s) {
        freeSpot = 0;
        a = new int[size];  // Allocate memory for the main array
        top = new int[n];   // Allocate memory for storing top indices
        next = new int[size]; // Allocate memory for next pointers

        // Initialize all stacks as empty
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next array for free slots management
        for (int i = 0; i < size - 1; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // Mark last index as end of free list
    }

    // Push operation
    bool push(int x, int m) {
        if (freeSpot == -1) {  // Stack overflow condition
            return false;
        }

        int index = freeSpot;   // Get the free index
        freeSpot = next[index]; // Update the freeSpot pointer

        a[index] = x;           // Insert element into the array

        next[index] = top[m - 1]; // Link current index with previous top
        top[m - 1] = index;       // Update the top of stack m

        return true;
    }

    // Pop operation
    int pop(int m) {
        if (top[m - 1] == -1) {  // Stack underflow condition
            return -1;
        }

        int index = top[m - 1];  // Get the top index of stack m
        top[m - 1] = next[index]; // Move top pointer to next available index

        int poppedElement = a[index]; // Get the popped value

        next[index] = freeSpot;  // Add this index back to the free list
        freeSpot = index;        // Update freeSpot pointer

        return poppedElement;
    }

    // Destructor to free allocated memory
    ~Nstack() {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

// Driver code
int main() {
    Nstack s(3, 6);

    cout << "Push 10 into Stack 1: " << s.push(10, 1) << endl;
    cout << "Push 20 into Stack 2: " << s.push(20, 2) << endl;
    cout << "Push 30 into Stack 3: " << s.push(30, 3) << endl;
    cout << "Push 40 into Stack 1: " << s.push(40, 1) << endl;
    
    cout << "Pop from Stack 1: " << s.pop(1) << endl;
    cout << "Pop from Stack 2: " << s.pop(2) << endl;
    cout << "Pop from Stack 3: " << s.pop(3) << endl;

    return 0;
}
