#include <iostream>
using namespace std;

class Student {

public:
    string name;

    // STATIC DATA MEMBER
    // Only ONE copy exists for the entire class
    static int count;

    Student() {
        // Every time an object is created,
        // increase the shared count
        count++;
    }
};

// Definition of static data member
int Student::count = 0;

int main() {

    Student s1;
    Student s2;
    Student s3;

    cout << "Number of students: " << Student::count << endl;

    return 0;
}