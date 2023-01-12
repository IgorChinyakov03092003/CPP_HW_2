#include "Header.h"

int Profit(int* arr, int N) {
    int left = arr[0];
    int ind_left = 0;
    int right = 0;
    int ind_right = 0;
    int profit = 0;
    for (int i = 1; i < N;i++) {
        if (arr[i] - left < 0) {
            left = arr[i];
            ind_left = i;
        }
        else {
            if (arr[i] - left > profit) {
                right = arr[i];
                ind_right = i;
                profit = arr[i] - left;
            }
        }
    }
    return profit;
}
// алгоритм: left - цена покупки, right - цена продажи
// на каждом шаге происходит обновление макс прибыли, если найден новый максимум
// если найдена меньшая цена покупки, то обновляется left, и остальные считываемые значения r-l сравниваются с уже сохраненной макс прибылью
// один проход по массиву
// если цена все время падает, выдает 0. Если цена постоянна, также 0
// если цена все время растет, выдает последний минус первый
