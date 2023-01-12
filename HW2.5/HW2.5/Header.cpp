#include "Header.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void alg(int* A, int* B, int N) {
    for (int i = 0; i < N; i++) {
        B[i] = A[i];
    }
    int stop = 0;
    for (int i = 0; i < N; i++) {
        if (B[i] < 0) {
            int k = i;
            while (k != stop) {
                swap(B + k, B + k - 1); //сдвиг отрицательных элементов к началу массива
                k--;
            }
            stop++; //переброс точки до которой сдвигать на 1 элемент вперед
        }
    }
}
