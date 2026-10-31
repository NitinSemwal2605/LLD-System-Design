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

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {

    Student s1("Rahul", 20);

    s1.display();

    return 0;
}