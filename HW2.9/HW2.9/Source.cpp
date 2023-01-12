#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    int* A = new int[15];
    for (int i = 0; i < 15; i++) {
        std::cin >> A[i];
    }
    int N1 = PosiCounter(A, 15);
    int N2 = MinusCounter(A, 15);
    int N3 = NullCounter(A, 15); //�������� ������������� ������������� �����
    int* A1 = new int[N1]; //����� � �������������� �������
    int* A2 = new int[N2]; //����� � �������������� �������
    int* A3 = new int[N3]; //����� � ������
    int ind = 0;
    for (int i = 0; i < 15; i++) {
        if (A[i] > 0) {
            A1[ind] = A[i];
            ind++;
        }
    }
    ind = 0;
    for (int i = 0; i < 15; i++) {
        if (A[i] < 0) {
            A2[ind] = A[i];
            ind++;
        }
    }
    ind = 0;
    for (int i = 0; i < 15; i++) {
        if (A[i] == 0) {
            A3[ind] = A[i];
            ind++;
        }
    }
    DownSorter(A1, N1); //���������� �� �������� �������������
    UpSorter(A2, N2);   //���������� �� ����������� �������������
    for (int i = 0; i < N2; i++) {
        A[i] = A2[i];
    }
    ind = 0;
    for (int i = N2; i < N2 + N3; i++) {
        A[i] = A3[ind];
        ind++;
    }
    ind = 0;
    for (int i = N2 + N3; i < 15; i++) {
        A[i] = A1[ind];
        ind++;
    }   //������������� ��������� �������
    for (int i = 0; i < 15; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n";
    delete[] A;
    delete[] A1;
    delete[] A2;
    delete[] A3;
    return 0;
}