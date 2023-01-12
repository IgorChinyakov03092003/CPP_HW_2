#include "Header.h"
#include <iostream>

void Pascal(int** A, int N) { // вывод треугольника паскаля
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                A[i][j] = 1;
            }
            else {
                if (i == j) {
                    A[i][j] = 1;
                }
                else {
                    A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
}
