#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int N;
    std::cin >> N;
    if (N <= 1) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* arr = new int[N];
        for (int i = 0; i < N; i++) {
            std::cin >> arr[i];
        }
        std::cout << "Max profit is: " << Profit(arr, N) << std::endl;
        delete[] arr;
    }
    return 0;
}