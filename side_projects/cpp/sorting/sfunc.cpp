#include "functions.hpp"
#include <iostream>         /* cout and shit */
#include <vector>           /* need I explain? */


void bubbleSort(std::vector<long> &vect) {
    // loop through vector
    long n = vect.size();
    for (int i = 0; i < n; i++) {
        // if previous element is larger than current, swap.
        if (vect[i-1] > vect[i]) {
            int temp = vect[i-1];
            vect[i-1] = vect[i];
            vect[i] = temp;
        }
    }
    // check if sorted least -> greatest. If not, sort again
    for (int i = 0; i < n; i++) {
        if (vect[i - 1] > vect[i])
            bubbleSort(vect);
    }
}


void selectionSort(std::vector<long> &vect) {
    // loop through vector
    for (int i = 0; i < vect.size(); i++) {
        // set index of minimum element to the first element
        int index = i;
        for (int j = i; j < vect.size(); j++) {
            // if element is less than the current minimum element, set new element to min
            if (vect[j] < vect[index]) {
                index = j;
            }
        }
        // swap the min element with the original place.
        int temp = vect[i];
        vect[i] = vect[index];
        vect[index] = temp;
    }
}


void insertionSort(std::vector<long> &vect) {
    // loop through vector
    for (int i = 0; i < vect.size(); i++) {
        // set the key to the current element
        // set j to the element preceding the key
        int key = vect[i];
        int j = i - 1;

        // compare key to predecessor. if key is less than predecessor, swap.
        // continue to do this until key is at front or is in proper place
        while (j >= 0 && key < vect[j]) {
            vect[j + 1] = vect[j];
            j -= 1;
        }
        // set the predecessor back to key
        vect[j + 1] = key;
    }
}


// find definition of partition() in hfunc.cpp
void quickSort(std::vector<long> &vect, int a, int b) {
    if (a < b) {
        // get the pivot of the array
        int i = partition(vect, a, b);
        // quick sort
        quickSort(vect, a, i-1);
        quickSort(vect, i + 1, b);
    }
}