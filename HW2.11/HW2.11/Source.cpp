#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int M;
    int N;
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
        Right(A, M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << A[i][j] << " ";
            }
            std::cout << "\n";
        }
        for (int i = 0; i < M; i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    return 0;
}