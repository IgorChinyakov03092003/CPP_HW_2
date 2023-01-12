#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    int N1;
    int N2;
    std::cin >> N1;
    std::cin >> N2;
    if ((N1 <= 0) || (N2 <= 0)) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* A = new int[N1];
        int* B = new int[N2];
        for (int i = 0; i < N1; i++) {
            std::cin >> A[i];
        }
        for (int i = 0; i < N2; i++) {
            std::cin >> B[i];
        }
        int MAX1 = MaxElem(A, N1);
        int MAX2 = MaxElem(B, N2);
        if (not((CountElem(A, N1, MAX1) == 1) && (CountElem(B, N2, MAX2) == 1))) { //нужно чтобы было ровно по 1 максимуму в каждом из массивов
            std::cout << "There must be only 1 maximum in array1 and only 1 maximum in array 2!" << std::endl;
        }
        else {
            int i1 = IndexOfMaxElem(A, N1);
            int i2 = IndexOfMaxElem(B, N2);
            std::cout << "Array 1" << std::endl;
            for (int i = 0; i < N1; i++) {
                std::cout << A[i] << " ";
            }
            std::cout << "\n";
            std::cout << "Array 2" << std::endl;
            for (int i = 0; i < N2; i++) {
                std::cout << B[i] << " ";
            }
            std::cout << "\n";
            std::cout << "Maximum of array1 is " << MAX1 << std::endl;
            std::cout << "Maximum of array2 is " << MAX2 << std::endl;
            std::cout << "After swapping" << std::endl;
            swap(*(A + i1), *(B + i2));
            std::cout << "Array 1" << std::endl;
            for (int i = 0; i < N1; i++) {
                std::cout << A[i] << " ";
            }
            std::cout << "\n";
            std::cout << "Array 2" << std::endl;
            for (int i = 0; i < N2; i++) {
                std::cout << B[i] << " ";
            }
            std::cout << "\n";
        }
        delete[] A;
        delete[] B;
    }
    return 0;
}