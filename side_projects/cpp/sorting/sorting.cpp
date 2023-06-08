#include "functions.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed with current time
    srand((unsigned) time(0));

    // define the test parameters
    const long testVectorLength = 100000;        //10,000
    const long testVectorMaxValue = 1000000;    //1,000,000

    // print test parameters
    std::cout << "Running algorithms on a randomized vector of size " << testVectorLength;
    std::cout << " and having a maximum element value of " << testVectorMaxValue << ".\n";

    // run tests
    for (int i = 1; i < 5; i ++) {
        testAlgorithm(i, testVectorLength, testVectorMaxValue);
    }

    return 0;
}