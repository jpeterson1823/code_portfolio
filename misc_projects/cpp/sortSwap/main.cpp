#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string>
#include <iostream>

#include "methods.hpp"

using namespace std;

int main()
{
    int* array = manualGetArray();
    printArray(array, 10);

    int* bubbleSorted = optimizedBubbleSort(array, 10);
    printArray(bubbleSorted, 10);

    int* selectionSorted = selectionSort(array, 10);
    printArray(selectionSorted, 10);

    delete[] array;
    delete[] bubbleSorted;
    delete[] selectionSorted;
    return 0;
}
