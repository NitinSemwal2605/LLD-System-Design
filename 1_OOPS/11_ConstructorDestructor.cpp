#include <iostream>
using namespace std;

class Student {
private:
    string name;

public:

    // =========================
    // CONSTRUCTOR
    // =========================
    // Same name as the class
    // No return type
    // Automatically called when object is created
    Student(string n) {
        name = n;

        cout << "Constructor called for "
             << name << endl;
    }


    // =========================
    // MEMBER FUNCTION
    // =========================
    void display() {
        cout << "Student Name: "
             << name << endl;
    }


    // =========================
    // DESTRUCTOR
    // =========================
    // Same name as class but starts with ~
    // No return type
    // Automatically called when object is destroyed
    ~Student() {
        cout << "Destructor called for "
             << name << endl;
    }
};


int main() {

    // Object s1 is created
    // Constructor is automatically called
    Student s1("Rahul");

    s1.display();

    // Object s2 is created
    // Constructor is automatically called
    Student s2("Aman");

    s2.display();

    // When main() ends:
    // Objects are destroyed automatically
    // Destructor will be called

    return 0;
}