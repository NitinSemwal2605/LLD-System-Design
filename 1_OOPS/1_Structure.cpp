#include <iostream>
using namespace std;

struct Student {
    string name;
    int age;
    float marks;
};

int main() {
    Student s1;

    s1.name = "Rahul";
    s1.age = 20;
    s1.marks = 85.5;

    cout << s1.name << endl;
    cout << s1.age << endl;
    cout << s1.marks << endl;

    return 0;
}

/*
 Structure is User Defined to Combine different types into single unit.
 All members of structure are stored in different memory locations.
 Structure is used to represent a record.
*/