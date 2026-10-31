#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int age;

    // Parameterized Constructor
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        age = s.age;
    }

    void display() {
        cout << name << " " << age << endl;
    }
};

int main() {

    Student s1("Rahul", 20);

    // Copy constructor is called
    Student s2 = s1;

    s1.display();
    s2.display();

    return 0;
}

/*
    Copy Constructor 
    Syntax: 
        ClassName(const ClassName &obj)
    About:
    - A copy constructor is a special constructor in C++ that is used to create a new object as a copy of an existing object. It is called when an object is initialized with another object of the same class.
    - The copy constructor takes a reference to an object of the same class as its parameter and creates
*/