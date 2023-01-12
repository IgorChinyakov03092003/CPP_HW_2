#include "Header.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int MaxElem(int* arr, int N) { //нахождение значения максимума массива
    if (N == 1) {
        return arr[0];
    }
    else {
        int max = arr[0];
        for (int i = 1; i < N; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
}
int IndexOfMaxElem(int* arr, int N) { //нахождение индекса максимального элемента массива
    int ind = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == MaxElem(arr, N)) {
            ind = i;
            break;
        }
    }
    return ind;
}
int CountElem(int* arr, int N, int El) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == El) {
            c++;
        }
    }
    return c;
}
