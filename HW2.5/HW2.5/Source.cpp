#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int N;
    std::cin >> N;
    if (N <= 0) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* A = new int[N];
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        int* B = new int[N];
        alg(A, B, N);
        for (int i = 0; i < N; i++) {
            std::cout << B[i] << " ";
        }
        std::cout << "\n";
        delete[] A;
        delete[] B;
    }
    return 0;
}