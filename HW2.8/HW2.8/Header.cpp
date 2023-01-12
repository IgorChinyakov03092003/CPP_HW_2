#include "Header.h"
#include <iostream>
int NulsCounter(int* arr, int N) {
    int c = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) {
            c++;
        }
    }
    return c; //счетчик нулей в строке
}
int NulsMatrix(int** A, int M, int N) {
    for (int i = 0; i < M; i++) {
        if (NulsCounter(A[i], N) != 2) {
            return 0;
            break;
        }
    }
    return 1;   //если во всех строках по 2 нуля, матрица корректна, иначе с ней нельзя работать
}
int NulSumArray(int* arr, int N) {
    int sum = 0;
    int ind = 0;
    while (arr[ind] != 0) {
        ind++;
    }
    do {
        ind++;
        sum += arr[ind];
    } while (arr[ind] != 0);
    return sum;
}   // подсчет сумм между нулями
void Summator(int** A, int M, int N) {
    for (int i = 0; i < M; i++) {
        std::cout << "Sum 0-0 for String " << i << " is equal to " << NulSumArray(A[i], N) << std::endl;
    }   // вывод сумм между нулями 
}
