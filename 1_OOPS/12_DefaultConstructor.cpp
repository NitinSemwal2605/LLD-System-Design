#include <iostream>
using namespace std;

class Student {
public:

    // Default Constructor
    Student() {
        cout << "Default Constructor Called" << endl;
    }
};

int main() {

    Student s1;  // Calls default constructor

    return 0;
}