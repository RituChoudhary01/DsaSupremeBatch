/*
Opps
Oppps:- Oops is a programing technique everything revolve around object.
Object:- Object is a entity which have state/properties and method/behaviour.
         object is a instance of class.

Class:- A class in C++ is a user-defined data type that acts as a blueprint  for creating objects. It encapsulates data (attributes) and functions (methods) that operate on that data.

the size of an empty class in C++ is 1 byte to ensure that each object of the class has a unique memory address.

Why is the size 1 byte?
If an empty class had zero size, multiple objects of the class would have the same memory address, leading to ambiguity.
To avoid this issue, the compiler assigns at least 1 byte to an empty class.

class Animal{
// state
int age;
string name;
};
sizeof of animal class is is 8bytes.


class Animal {
    int age;    // 4 bytes
    char gender; // 1 byte
    int lage;   // 4 bytes
};
sizeof of animal class is is 12bytes. here we introduce new concept of Padding and Greedy Alignment.

Padding:- Padding refers to extra bytes added by the compiler to align data members for efficient memory access.

Why does padding exist?
1.CPU reads memory in chunks (e.g., 4 or 8 bytes) instead of individual bytes.
2.Misaligned data can lead to performance issues.
3.Padding ensures that larger data types (like int, double) are aligned properly in memory.

Greedy Alignment:- Greedy alignment is a technique where the compiler tries to align members efficiently by placing larger data types first to reduce padding.

agar tum kisi object ki property ko access karna chahte ho, toh dot (.) operator ka use karna padega.

agar pointer object ko access karna ho toh arrow (->) operator ka use karna padega.

Access Modifiers in C++ 
1.Public
2.Private
3.Protected.

#include <iostream>
using namespace std;

class Animal {
public:
    int age;
    string name;
};

int main() {
    //    stastic memory allocation
    Animal dog;  // Object of class Animal
    dog.age = 5;  // Using dot operator to assign value
    dog.name = "Bruno";

    cout << "Dog Name: " << dog.name << endl;
    cout << "Dog Age: " << dog.age << " years" << endl;

    // dynamic memory allocation.
    Animal *cat = new Animal();  // Dynamic object
    cat->age = 3;  // Using arrow operator to assign value
    cat->name = "Whiskers";

    cout << "Cat Name: " << cat->name << endl;
    cout << "Cat Age: " << cat->age << " years" << endl;
    return 0;
}

agar koi property ya behavior (function) public mark ho, toh use class ke andar bhi aur bahar bhi access kar sakte hain.

private members sirf class ke andar access ho sakte hain aur by default saare class ke members private hote hain.

agar hame kisi private member ko class ke bahar access karna hai, toh ham "Getter" aur "Setter" functions ka use kar sakte ho.

#include <iostream>
using namespace std;

class Animal {
private:
    string name; 
    int age;      

public:
    // Setter function to assign values
    void setData(string n, int a) {
        name = n;
        age = a;
    }

    // Getter function to retrieve name
    string getName() {
        return name;
    }

    // Getter function to retrieve age
    int getAge() {
        return age;
    }
};

int main() {
    Animal dog;
    
    dog.setData("Bruno", 5);
    // Accessing private members using getter
    cout << "Dog Name: " << dog.getName() << endl;
    cout << "Dog Age: " << dog.getAge() << " years" << endl;
    return 0;
}

this pointer C++ me current object ko refer karta hai. Jab bhi ek non-static member function call hota hai, toh this pointer uss function ke andar current object ka address store karta hai.

#include <iostream>
using namespace std;
class Animal {
private:
    string name;
    int age;
public:
    // Setter function using 'this' pointer
    void setData(string name, int age) {
        this->name = name;  // 'this' refers to the current object
        this->age = age;
    }

    void display() {
        cout << "Name: " << this->name << ", Age: " << this->age << " years" << endl;
    }
};

int main() {
    Animal dog;
    dog.setData("Bruno", 5);
    dog.display(); 
   return 0;
}

Constructor :-
A constructor is a special member function that gets automatically called when an object of the class is created.

Types of Constructors
Default Constructor (No parameters)
Parameterized Constructor (With parameters)
Copy Constructor (Creates a copy of another object)

#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    // Default Constructor
    Animal() {
        cout << "Default Constructor Called\n";
    }

    //Parameterized Constructor
    Animal(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized Constructor Called\n";
    }

    // Copy Constructor
    Animal(const Animal &a) {
        name = a.name;
        age = a.age;
        cout << "Copy Constructor Called\n";
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << " years\n";
    }
};

   int main() {
    Animal a1;  // Default constructor will be called
    a1.display();

    Animal a2("Tiger", 5);  // Parameterized constructor will be called
    a2.display();

    Animal a3 = a2;  // Copy constructor will be called
    a3.display();
   return 0;
}

If we do not pass the object by reference in a copy constructor, it will cause an infinite loop and eventually a stack overflow error.
Animal(Animal a)(wrong way).
It tries to create a copy of a using the same copy constructor.
But to copy a, another call to the copy constructor is made, which again tries to copy a, and this keeps repeating forever!

Constructor Overloading:-
Constructor overloading means having multiple constructors in the same class with different parameters. C++ automatically calls the right constructor based on the number and type of arguments passed during object creation.

#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    //Default Constructor (No parameters)
    Animal() {
        name = "Unknown";
        age = 0;
        cout << "Default Constructor Called\n";
    }

    // Parameterized Constructor (With name only)
    Animal(string n) {
        name = n;
        age = 0;
        cout << "Parameterized Constructor (Name) Called\n";
    }

    //Parameterized Constructor (With name & age)
    Animal(string n, int a) {
        name = n;
        age = a;
        cout << "Parameterized Constructor (Name & Age) Called\n";
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << " years\n";
    }
};

int main() {
    Animal a1;           // Calls Default Constructor
    Animal a2("Tiger");  // Calls Constructor with name
    Animal a3("Lion", 5); // Calls Constructor with name & age

    a1.display();
    a2.display();
    a3.display();

    return 0;
}


Destructor:-
A destructor is a special member function in C++ that automatically gets called when an object goes out of scope or is deleted. It is used to release resources like memory, file handles, or network connections.
Same name as class but with a tilde (~) prefix.
No parameters & no return type.
Automatically invoked when an object is destroyed.
Only one destructor per class (cannot be overloaded).

#include <iostream>
using namespace std;

class Animal {
public:
    string name;

    // Constructor
    Animal(string n) {
        name = n;
        cout << "Constructor called for " << name << endl;
    }

    // Destructor
    ~Animal() {
        cout << "Destructor called for " << name << endl;
    }
};

int main() {
    Animal a1("Tiger");  
    {
        Animal a2("Lion");  
    } 
    return 0;
} 

       */