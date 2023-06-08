// FullAdder.cpp
#include "FullAdder.hpp"

FullAdder::FullAdder(bool a0, bool b0, bool a1, bool b1)
    : a0(a0), b0(b0), a1(a1), b1(b1) {
    
}

bool FullAdder::getC() {
    return this->c;
}

bool FullAdder::getS() {
    return this->s;
}
