#include <iostream>
using namespace std;

class Student {
private:
    int marks = 90;

public:
    friend void display(Student s);
};

void display(Student s) {
    cout << s.marks;
}

int main() {

    Student s;

    display(s);

    return 0;
}


/*
A friend function is a function that is not a member of a class, but it is allowed to access the class's private and protected members.
*/