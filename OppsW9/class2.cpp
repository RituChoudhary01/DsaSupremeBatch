/*
The four pillars of OOPs are: 
1.Encapsulation
Hides data and methods from outside of a class
2.Inheritance
Allows objects to inherit characteristics from other objects
3.Polymorphism
Allows objects to take on multiple forms
4.Abstraction
Hides complexity and only shows essential features of an object

1.Encapsulation
 Encapsulation is one of the four pillars of Object-Oriented Programming. It means hiding data and providing controlled access through public methods (getters & setters).

 #include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;

public:
    // Setter methods (to set private data)
    void setName(string n) {
        name = n;
    }
    
    void setAge(int a) {
        if (a < 0) {
            cout << "Age cannot be negative!" << endl;
            return;
        }
        age = a;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
};

int main() {
    Animal a;
    a.setName("Tiger");
    a.setAge(5);
    cout << "Animal: " << a.getName() << ", Age: " << a.getAge() << endl;
    return 0;
}
Perfect Encapsulation :- All data members should be private.

Inheritance:-
Inheritance is a key feature of Object-Oriented Programming that allows a class to inherit properties and behaviors (variables & methods) from another class.
Why Use Inheritance?
 Code Reusability – Avoid rewriting code, use existing class features.
 Modularity – Organize code into a hierarchy of classes.
 Extensibility – Easily add new features without modifying old code.

 #include <iostream>
using namespace std;

// Base class (Parent)
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Derived class (Child) - Inheriting from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog d;
    d.eat();  // Calling inherited method from Animal
    d.bark(); // Calling Dog's own method

    return 0;
}

Effect of Inheritance Mode on Base Class Members
Base Class Access Modifier	Public Inheritance	Protected Inheritance	Private Inheritance
public members	  Remain public	     Become protected	 Become private
protected members Remain protected	 Remain protected	 Become private
private members	  Not accessible	 Not accessible	     Not accessible


#include <iostream>
using namespace std;

class Base {
public:
    int pub = 1;       // Public member
protected:
    int prot = 2;      // Protected member
private:
    int priv = 3;      // Private member (Not accessible in derived class)
};

//Public Inheritance: Public → Public, Protected → Protected
class PublicDerived : public Base {
public:
    void show() {
        cout << "Public: " << pub << endl;   //  Allowed (remains public)
        cout << "Protected: " << prot << endl; // Allowed (remains protected)
        // cout << "Private: " << priv << endl;  Not accessible
    }
};

//  Protected Inheritance: Public → Protected, Protected → Protected
class ProtectedDerived : protected Base {
public:
    void show() {
        cout << "Public → Protected: " << pub << endl;  //  Becomes protected
        cout << "Protected: " << prot << endl; //Allowed (remains protected)
    }
};

// Private Inheritance: Public → Private, Protected → Private
class PrivateDerived : private Base {
public:
    void show() {
        cout << "Public → Private: " << pub << endl;   // 🔒 Becomes private
        cout << "Protected → Private: " << prot << endl; // 🔒 Becomes private
    }
};

int main() {
    PublicDerived obj1;
    obj1.show();
    cout << "Accessing Public Member from Main: " << obj1.pub << endl;  // ✅ Allowed (remains public)

    ProtectedDerived obj2;
    obj2.show();
    // cout << obj2.pub;  Not accessible (became protected)

    PrivateDerived obj3;
    obj3.show();
    // cout << obj3.pub;  Not accessible (became private)

    return 0;
}

Types of Inheritance
1.Single Inheritance
2.Multiple Inheritance
3.Multilevel Inheritance
4.Hierarchical Inheritance
5.Hybrid (Multiple + Multilevel) Inheritance

1.Single Inheritance:-
A single derived class inherits from a single base class.
#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};

// Derived Class
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog d;
    d.eat();  
    d.bark();
    return 0;
}

2.Multiple Inheritance
A single child class inherits from multiple parent classes.
Used when a class needs functionality from multiple sources.
#include <iostream>
using namespace std;

// Base Class 1
class Father {
public:
    void wealth() {
        cout << "Father has wealth." << endl;
    }
};

// Base Class 2
class Mother {
public:
    void love() {
        cout << "Mother gives love." << endl;
    }
};

// Derived Class
class Child : public Father, public Mother {
public:
    void play() {
        cout << "Child loves to play." << endl;
    }
};

int main() {
    Child c;
    c.wealth();  // From Father
    c.love();    // From Mother
    c.play();   
    return 0;
}

Diamond Problem 
The Diamond Problem occurs in Multiple Inheritance when a class inherits from two classes that both inherit from a common base class. This creates ambiguity because the derived class gets two copies of the base class members.

Solving the Diamond Problem Using virtual Inheritance
#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A Show Function" << endl;
    }
};

// Use virtual inheritance
class B : virtual public A {};
class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.show();  // No ambiguity now
    return 0;
}


3.Multilevel Inheritance
A derived class becomes the base class for another class.
Forms a chain-like hierarchy.
#include<iostream>
using namespace std;
class Fruit{
public:
string name;
}
class Mango:public Fruit{
public:
int weight;
};
class Alphanso:public Mango{
public:
int sugerLevel;
};
int main(){
Alphanso a;
cout<<a.name<<" "<<a.weight<<" "<<a.sugerLevel<<endl;
return 0;
}

4.Hierarchical Inheritance
 Multiple derived classes inherit from a single base class.
Useful when multiple classes share common features.

#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Derived Class 1
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks." << endl;
    }
};

// Derived Class 2
class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows." << endl;
    }
};

int main() {
    Dog d;
    d.eat();  // Inherited from Animal
    d.bark(); // Dog-specific method

    Cat c;
    c.eat();  // Inherited from Animal
    c.meow(); // Cat-specific method

    return 0;
}

5.Hybrid (Multiple + Multilevel) Inheritance
 Combination of two or more types of inheritance.
Usually involves Multiple + Multilevel Inheritance.

#include <iostream>
using namespace std;

// Base Class
class Animal {
public:
    void eat() {
        cout << "Animal eats food." << endl;
    }
};

// Intermediate Derived Class 1
class Mammal : public Animal {
public:
    void walk() {
        cout << "Mammal walks." << endl;
    }
};

// Intermediate Derived Class 2
class Bird : public Animal {
public:
    void fly() {
        cout << "Bird flies." << endl;
    }
};

// Derived Class from both Mammal & Bird
class Bat : public Mammal, public Bird {
public:
    void echoLocation() {
        cout << "Bat uses echolocation." << endl;
    }
};

int main() {
    Bat b;
    b.walk();         // From Mammal
    b.fly();          // From Bird
    b.echoLocation(); // Own method
    return 0;
}

Polymorphism:-
Polymorphism means "many forms." It allows a function, method, or operator to behave differently based on the object or data type.

Types of Polymorphism in C++:
1️ Compile-time Polymorphism (Static Binding)
   Function Overloading
   Operator Overloading
2️ Run-time Polymorphism (Dynamic Binding)
Function Overriding (with Virtual Functions)

Function Overloading:-
 Multiple functions with the same name but different parameters.
The compiler decides which function to call based on the function signature.

#include <iostream>
using namespace std;

class Math {
public:
    // Function to add two numbers
    int add(int a, int b) {
        return a + b;
    }

    // Function to add three numbers
    int add(int a, int b, int c) {
        return a + b + c;
    }

    // Function to add two floating-point numbers
    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math obj;
    cout << obj.add(2, 3) << endl;       // Calls add(int, int)
    cout << obj.add(2, 3, 5) << endl;    // Calls add(int, int, int)
    cout << obj.add(2.5, 3.5) << endl;   // Calls add(double, double)
    return 0;
}

Operator Overloading
 Allows operators (+, -, *, etc.) to work with user-defined data types.

#include<iostream>
using namespace std;
class Param{
public:
int val;
void operator+(Param &obj2){
int value1 = this->val;
int value2 = obj2.val;
cout<<(value2-value1)<<endl;
}
};
int main(){
Parem object1,object2;
object1.val = 7;
object2.val = 2;
object1+object2;
return 0;
}

*/ 