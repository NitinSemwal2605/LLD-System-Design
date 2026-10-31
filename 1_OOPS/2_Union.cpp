#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};

int main() {
    Data d;

    d.i = 10;
    cout << d.i << endl;

    d.f = 3.14;
    cout << d.f << endl;

    d.c = 'A';
    cout << d.c << endl;

    return 0;
}


/*
 Union is User Defined to Combine different types into single unit.
 All members of union are stored in same memory location.
 Union is used to represent a record.
*/