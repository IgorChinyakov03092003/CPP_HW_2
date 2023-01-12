#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    int N = 12;
    double* A = new double[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int partitions = 0;
    for (int i = N - 2; i >= 0; i--) {
        int k = i;
        while (A[k] < A[k + 1]) {
            swap(*(A + k), *(A + k + 1));
            partitions++;
            k++;
            if (k == N - 1) {
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Number of partitions is: " << partitions << std::endl;
    delete[] A;
    return 0;
}