#include <iostream>

using namespace std;

int main()
{
    int N;
    std::cin >> N;
    if (N <= 2) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* A = new int[N];
        for (int i = 0; i < N; i++) {
            std::cin >> A[i];
        }
        int k = 0;
        for (int i = 1; i <= N - 2; i++) {  // проход по тройкам чисел
            if ((A[i] < A[i - 1]) && (A[i] < A[i + 1])) {
                k++;
            }
        }
        std::cout << "Number of local minimums is: " << k << std::endl;
        delete[] A;
    }
    return 0;
}