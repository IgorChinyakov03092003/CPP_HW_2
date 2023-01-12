#include "Header.h"

void Right(int** A, int M, int N) { //алгоритм сдвига
    for (int i = 0; i < M; i++) {
        int last = A[i][N - 1];
        for (int j = N - 1; j >= 1; j--) {
            A[i][j] = A[i][j - 1];
        }
        A[i][0] = last;
    }
}
