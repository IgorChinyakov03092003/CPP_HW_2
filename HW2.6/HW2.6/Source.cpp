#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    double* A = new double[14];
    for (int i = 0; i < 14; i++) {
        std::cin >> A[i];
    }
    int partitions = 0;
    for (int i = 0; i < 7; i++) {
        if (A[i] != A[i + 7]) {
            swap(*(A + i), *(A + i + 7));
            partitions++;
        }
    }
    for (int i = 0; i < 14; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Number of partitions is: " << partitions << std::endl;
    delete[] A;
    return 0;
}