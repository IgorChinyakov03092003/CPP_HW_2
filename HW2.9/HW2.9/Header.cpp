#include "Header.h"

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int PosiCounter(int* arr, int N) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            c++;
        }
    }
    return c;
}
int MinusCounter(int* arr, int N) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            c++;
        }
    }
    return c;
}
int NullCounter(int* arr, int N) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            c++;
        }
    }
    return c;
}
void UpSorter(int* arr, int N) {
    for (int i = 1; i < N; i++) {
        int k = i;
        while (arr[k] < arr[k - 1]) {
            swap(arr + k, arr + k - 1);
            k--;
            if (k - 1 < 0) {
                break;
            }
        }
    }
}
void DownSorter(int* arr, int N) {
    for (int j = 1; j < N; j++) {
        int p = j;
        while (arr[p] > arr[p - 1]) {
            swap(arr + p, arr + p - 1);
            p--;
            if (p - 1 < 0) {
                break;
            }
        }
    }
}   //сортировки по возрастанию и убыванию на основе сортировки вставками
