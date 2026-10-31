#include <iostream>
using namespace std;

class Student {

private:
    // PRIVATE member
    // Can be accessed only inside the Student class
    int marks;

protected:
    // PROTECTED member
    // Can be accessed inside Student and its child/derived classes
    int rollNo;

public:
    // PUBLIC member
    // Can be accessed from outside the class
    string name;

    // PUBLIC MEMBER FUNCTION
    // This function can be called from outside the class
    void setData(string n, int r, int m) {
        name = n;

        // We can access private and protected members
        // because we are inside the class
        rollNo = r;
        marks = m;
    }

    // Another member function
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main() {

    Student s;

    // PUBLIC member → allowed
    s.name = "Rahul";

    // PRIVATE member → NOT allowed
    // s.marks = 90;        // ❌ Error

    // PROTECTED member → NOT allowed from outside
    // s.rollNo = 101;     // ❌ Error

    // We use a public member function
    // to access private/protected data
    s.setData("Rahul", 101, 90);

    s.display();

    return 0;
}