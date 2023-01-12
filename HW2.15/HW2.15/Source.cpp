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
        int** A;
        A = new int* [N];
        for (int i = 0; i < N; i++) {
            A[i] = new int[i + 1];  //для экономии память можно выделять только для нижней половины матрицы
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                A[i][j] = 0;
            }
        }
        Pascal(A, N);
        for (int i = 0; i < N; i++) {
            delete[] A[i];
        }
        delete[] A;
    }
    return 0;
}