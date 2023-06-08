#include <vector>
#include <string>

void bubbleSort(std::vector<long> &vect);
void selectionSort(std::vector<long> &vect);
void insertionSort(std::vector<long> &vect);
int partition(std::vector<long> &vect, int a, int b);
void quickSort(std::vector<long> &vect, int a, int b);
std::string vtostr(std::vector<long> vect);
std::vector<long> genVect(long elements, long maxNumber);
void testAlgorithm(int algorithmNumber, long testVectLength, long testVectMaxNum);