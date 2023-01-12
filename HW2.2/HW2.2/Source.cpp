#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    int N;
    std::cin >> N;
    int* A = new int[N];
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int* pa = A;
    int* pla = A + N - 1;
    swap(pa, pla);
    for (int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
    delete[] A;
    return 0;
}