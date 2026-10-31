#include <iostream>
using namespace std;

// Call by Value
void changeValue(int x) {
    x = 100;
}

// Call by Reference
void changeReference(int &x) {
    x = 100;
}

int main() {

    int a = 10;
    int b = 10;

    // Call by Value
    changeValue(a);

    // Call by Reference
    changeReference(b);

    cout << "After Call by Value: " << a << endl;
    cout << "After Call by Reference: " << b << endl;

    return 0;
}


/* Call by Value and Call by Reference 
    - Call by Value: In this method, a copy of the actual parameter is passed to the function. Changes made to the parameter inside the function do not affect the original argument.
    - Call by Reference: In this method, a reference (or address) of the actual parameter is passed to the function. Changes made to the parameter inside the function affect the original argument.
*/