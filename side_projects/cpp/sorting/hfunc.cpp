#include "functions.hpp"    /* all function prototypes              */
#include <string>           /* need I explain?                      */
#include <iostream>         /* cout and shit                        */
#include <chrono>           /* steady_clock and its dependencies    */
#include <stdlib.h>         /* rand()                               */


// Given a vector of type long, return a string of the first ten elements
// along with the number of remaining elements.
std::string vtostr(std::vector<long> vect) {
    // create string to be printed later along with its delimiter
    std::string str = "[";
    std::string delimiter = ", ";

    // add the first ten elements to the array
    for (int i = 0; i < 10; i++) {
        str += std::to_string(vect[i]);
        if (i != vect.size() - 1)       // don't add delimiter if last element
            str += delimiter;
    }
    // state how many more items are in the array and close the brakets
    str += "... (" + std::to_string(vect.size() - 10) + " more)]";
    return str;
}


// Generates a vector of longs with a specific number of elements with
// a max value.
std::vector<long> genVect(long elements, long maxNumber) {
    // use long vector due to max number being 10,000,000
    std::vector<long> vect;
    // add random numbers to vector
    for (int i = 0; i < elements; i++) {
        vect.push_back(rand() % maxNumber);
    }
    return vect;
}


// used for quick sort
int partition(std::vector<long> &vect, int a, int b) {
    // not sure how this works, look this up
    int i = a - 1;
    int pivot = vect[b];
    for (int j = a; j < b; j++) {
        if (vect[j] < pivot) {
            i += 1;
            int temp = vect[i];
            vect[i] = vect[j];
            vect[j] = temp;
        }
    }
    int temp = vect[i + 1];
    vect[i + 1] = vect[b];
    vect[b] = temp;
    return i + 1;
}


// Runs each sorting algorithm and times how long it takes to do its thing
void testAlgorithm(int algorithmNumber, long testVectLength, long testVectMaxNum) {
    // create test vector and print original arrangement
    std::vector<long> vect = genVect(testVectLength, testVectMaxNum);
    std::cout << "Original: " + vtostr(vect) + '\n';

    // sort the array using the requested method and record what algorithm was used
    // as well as how long the function took to complete the sorting
    std::string algorithm;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;
    switch (algorithmNumber) {
        case 1:
            std::cout << "\tStarting a bubble sort...\n";
            algorithm = "Bubble";
            begin = std::chrono::steady_clock::now();
            bubbleSort(vect);
            end = std::chrono::steady_clock::now();
            break;

        case 2:
            std::cout << "\tStarting a selection sort...\n";
            algorithm = "Selection";
            begin = std::chrono::steady_clock::now();
            selectionSort(vect);
            end = std::chrono::steady_clock::now();
            break;
            
        case 3:
            std::cout << "\tStarting an insertion sort...\n";
            algorithm = "Insertion";
            begin = std::chrono::steady_clock::now();
            insertionSort(vect);
            end = std::chrono::steady_clock::now();
            break;
        
        case 4:
            std::cout << "\tStarting a quick sort...\n";
            algorithm = "Quick";
            begin = std::chrono::steady_clock::now();
            quickSort(vect, 0, vect.size() - 1);
            end = std::chrono::steady_clock::now();
            break;
    }
    // Print out which algorithm was used and the sorted array, along with time elapesd in seconds
    long dtMicro = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    double dtSec = (double)dtMicro / (double)1000000.0;
    std::cout << '\t' + algorithm + " Sorted: " + vtostr(vect) + '\n';
    std::cout << "\t\tTime elapsed: ";
    std::cout << dtSec << "s\n";
}