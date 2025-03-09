/*
Run-Time Polymorphism
In run-time polymorphism, the function that gets executed is determined at runtime.
 Achieved using function overriding and virtual functions.
 Requires base class pointer pointing to derived class object.

#include <iostream>
using namespace std;

class Animal{
        public:
        Animal() {
                cout << "i am inside animal constructor" << endl;
        }
         void speak() {
                cout << "Speaking " << endl;
        }
};

class Dog: public Animal {
        public:
        Dog() {
                cout << "i am inside Dog constructor" << endl;
        }
        //override
        void speak() {
                cout << "barking" << endl;
        }
};

int main() {
        // Dog a1;
        // a1.speak();

        Animal* a2 = new Animal();
        a2->speak();

        Dog* a3 = new Dog();
        a3->speak();

        // UpCasting
        Animal* a4 = new Dog();
        a4->speak();

        //DownCasting
        Dog* b = (Dog* )new Animal();
        b->speak();

        // Dog* a5 = (Dog*)new Animal();
        // Dog a5;

      return 0;
}
Function Overriding
 A derived class provides a new definition of a function that already exists in the base class.
The base class function must be marked as virtual.

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() { // Virtual function
        cout << "Animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override { // Overriding the base class function
        cout << "Dog barks." << endl;
    }
};

int main() {
    Animal* a;  // Base class pointer
    Dog d;
    a = &d;  // Pointer to derived class object
    a->sound();  // Calls Dog's sound() because of virtual function
    return 0;
}

Abstraction:-  it is an Object-Oriented Programming concept that hides the internal implementation details and only shows the necessary functionalities to the user.
It helps in reducing complexity by hiding unnecessary details.

#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() = 0;  // Pure virtual function (abstract method)
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.sound();
    return 0;
}

Static vs Dynamic Memory in C++
In C++, memory is divided into two main types:
 Static Memory (Compile-Time Allocation)
 Dynamic Memory (Run-Time Allocation)


1.Static Memory Allocation (Compile-Time Memory)
  Memory is allocated at compile-time.
  Fixed size, cannot be changed at runtime.
  Stored in stack or global memory.
 Automatically deallocated when the function exits or program ends.

 Example: Static Memory Allocation
#include <iostream>
using namespace std;

void staticMemory() {
    int x = 10;  // Memory allocated at compile-time
    cout << "Value of x: " << x << endl;
} // x is automatically deallocated when function ends

int main() {
    staticMemory();
    return 0;
}
Dynamic Memory Allocation (Run-Time Memory)
 Memory is allocated at runtime using new keyword.
 Size can be changed dynamically.
  Stored in heap memory.
  Must be manually deallocated using delete (or delete[] for arrays).
  #include <iostream>
  using namespace std;

void dynamicMemory() {
    int* ptr = new int(20);  // Allocate memory in heap
    cout << "Value: " << *ptr << endl;

    delete ptr;  // Free allocated memory
}

int main() {
    dynamicMemory();
    return 0;
}
Dynamic Memory for 1D Array
If we don’t know array size at compile-time, we allocate it dynamically.
Use new[] to allocate and delete[] to free memory.

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];  // Dynamic array allocation
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;  // Free memory
    return 0;
}
Dynamic Memory for 2D Array
#include <iostream>
using namespace std;

int main() {
        int row = 5;
        int col = 3;

        int** arr = new int*[5];

        for(int i=0; i<row; i++) {
                arr[i] = new int[col];
        }

        //printing
        for(int i=0; i<row; i++) {
                for(int j=0; j<col; j++) {
                        cout << arr[i][j] <<" ";
                }
                cout << endl;
        }

        //de-allocate
        for(int i=0; i<row; i++) {
                delete []arr[i];
        }

        delete []arr;
        return 0;
}

initial of 2D vector
#include <iostream>
#include<vector>
using namespace std;

int main() {
        vector<vector<int> > arr(5, vector<int>(6,0));

        for(int i=0; i<5; i++) {
                for(int j=0; j<6; j++) {
                        cout << arr[i][j] << " ";
                }
    cout << endl;    }
  
  return 0;
}
*/ 