#include "fraction.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    Fraction a(2,6);
    Fraction b(1,6);
    Fraction c = a + b;
    cout << c.toString() << endl;

    c -= a;
    cout << c.toString() << endl;
    return 0;
}