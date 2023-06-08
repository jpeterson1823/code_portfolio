// HalfAdder.cpp
#include "HalfAdder.hpp"

HalfAdder::HalfAdder(bool a, bool b) : a(a), b(b) {
    bool and1 = (a && !b);
    bool and2 = (!a && b);
    this->c = (a && b);
    this->s = (and1 || and2);
}

bool HalfAdder::getC() {
    return this->c;
}

bool HalfAdder::getS() {
    return this->s;
}
