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
        int** A;
        A = new int* [M];
        for (int i = 0; i < M; i++) {
            A[i] = new int[N];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cin >> A[i][j];
            }
        }
        if (NulsMatrix(A, M, N) == 0) {
            std::cout << "We can't work with this matrix!" << std::endl;
        }
        else {
            std::cout << "Our matrix is:" << std::endl;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    std::cout << A[i][j] << " ";
                }
                std::cout << "\n";
            }
            Summator(A, M, N);
            for (int i = 0; i < M; i++) {
                delete[] A[i];
            }
            delete[] A;
        }
    }
    return 0;
}