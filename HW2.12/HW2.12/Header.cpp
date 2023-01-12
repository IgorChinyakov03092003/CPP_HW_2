#include "Header.h"

int Sum(int* arr, int N) { //сумма элементов строки
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}
