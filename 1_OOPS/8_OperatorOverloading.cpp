#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Operator overloading
    Complex operator+(Complex c) {
        Complex temp(0, 0);

        temp.real = real + c.real;
        temp.imag = imag + c.imag;

        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {

    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1 + c2;

    c3.display();

    return 0;
}


/*
Operator Overloading 
    - Operator overloading is a feature in C++ that allows developers to redefine the way operators work for user-defined types (classes). It enables the use of operators such as +, -, *, /, etc., with objects of custom classes, making the code more intuitive and readable.
    - By overloading operators, you can define how they behave when applied to instances of your classes, allowing for more natural expressions and operations on objects.
*/