#include <string>
#include <vector>
#include <cstring>
#include <ctype.h>
#include <iostream>

using namespace std;

inline void printArray(int* array, int arrayLength)
{
    cout << "Printing Array: [";
    for (int i = 0; i < arrayLength - 1; i++) {
        cout << *(array + i) << ", ";
    }
    cout << *(array + arrayLength - 1) << ']' << endl;
}


inline void swapPVals(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


// Creates and returns the array .
inline int* manualGetArray()
{
    int* array = new int[10];
    
    // Get user-inputed seed and verify that only integers were entered.
    string userSeed;
    while (true)
    {
        cout << "Please enter a random string of up to 10 integers: ";
        cin >> userSeed;

        bool reloop = false;
        if (userSeed.length() > 10)
        {
            cout << "Please enter no more than 10 integers." << endl;
            reloop = true;
        }
        else
        {
            for (int i = 0; i < userSeed.length(); i++) {
                if (!isdigit(userSeed[i])) {
                    cout << "Please only use INTEGER values for the seed." << endl;
                    reloop = true;
                }
            }
        }

        if (!reloop)
            break;
    }

    // Set random seed and populate array with randomly generated integers.
    //srand(stoi(userSeed));
    srand(123);
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100 + 1;
    }

    return array;
}


inline int* optimizedBubbleSort(int* array, int arrayLength)
{
    // Create new copy in a unique memory location
    int* data = new int[arrayLength];
    memcpy(data, array, sizeof(array) * arrayLength);

    for (int i = 0; i < arrayLength; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arrayLength - i - 1; j++)
        {
            int* p1 = data + j;
            int* p2 = data + j + 1;

            if (*p1 > *p2)
            {
                swapPVals(p1, p2);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    return data;
}


int* selectionSort(int* array, int arrayLength)
{
    int* data = new int[arrayLength];
    memcpy(data, array, sizeof(array) * arrayLength); 
 
    for (int i = 0; i < arrayLength - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arrayLength; j++)
        {
            int* p1 = data + j;
            int* p2 = data + minIndex;
            if (*p1 < *p2)
                minIndex = j;
        }
        swapPVals(data + i, data + minIndex);
    }
    return data;
}


int* insertionSort(int* array, int arrayLength)
{
    int* data = new int(arrayLength);
    memcpy(data, array, sizeof(array) * arrayLength);

    int i, key, j;
    for (i = 1; i < arrayLength; i++)
    {
    	key = *(data + i);
    	j = i - 1;

    	while (j >= 0 && *(data + j) > key)
    	{
    		*(data + j + 1) = *(data + j);
    		j = j - 1;
    	}
    	*(data + j + 1) = key;
    }

    return data;
}
