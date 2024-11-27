#include <iostream>
using namespace std;

// Define prototype
int* arrTest(int numOfSpaces);

int main()
{
    // Prompt user to enter number of integers
    // to be held in the array.
    cout << "How many integers in array? ";
    int numOfSpaces = 0;
    cin >> numOfSpaces;

    // Create the pointer to store the returned
    // value
    int* test = arrTest(numOfSpaces);
    for (int i = 0; i < numOfSpaces; i++)
        cout << *(test + i) << endl;
    return 0;
}

int* arrTest(int numOfSpaces)
{
    int* testArr = new int[numOfSpaces];
    for (int i = 0; i < numOfSpaces; i++)
        *(testArr + i) = i;
    return testArr;
}