#include <iostream>
#include "Header.h"
using namespace std;

int main()
{

    int M, N;
    std::cin >> M;
    std::cin >> N;
    if ((M <= 0) || (N <= 0)) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int maxSum = 0;
        int minSum = 0;
        int** A;
        A = new int* [M];
        for (int i = 0; i < M; i++) {
            A[i] = new int[N];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> A[i][j];
                if (A[i][j] > minSum) {
                    minSum = A[i][j];
                }
                if (A[i][j] < maxSum) {
                    maxSum = A[i][j];
                }
            }
        }
        minSum *= N;
        maxSum *= N;
        for (int i = 0; i < M; i++) {
            if (Sum(A[i], N) > maxSum) {
                maxSum = Sum(A[i], N);
            }
            if (Sum(A[i], N) < minSum) {
                minSum = Sum(A[i], N);
            }
        }
        std::cout << "MaxSum is: " << maxSum << std::endl;
        std::cout << "Indexes of MaxSum are: ";
        for (int i = 0; i < M; i++) {
            if (Sum(A[i], N) == maxSum) {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
        std::cout << "MinSum is: " << minSum << std::endl;
        std::cout << "Indexes of MinSum are: ";
        for (int i = 0; i < M; i++) {
            if (Sum(A[i], N) == minSum) {
                std::cout << i << " ";
            }
        }
        std::cout << "\n";
        for (int i = 0; i < M; i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    return 0;
}