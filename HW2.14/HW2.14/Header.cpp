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
// ��������: left - ���� �������, right - ���� �������
// �� ������ ���� ���������� ���������� ���� �������, ���� ������ ����� ��������
// ���� ������� ������� ���� �������, �� ����������� left, � ��������� ����������� �������� r-l ������������ � ��� ����������� ���� ��������
// ���� ������ �� �������
// ���� ���� ��� ����� ������, ������ 0. ���� ���� ���������, ����� 0
// ���� ���� ��� ����� ������, ������ ��������� ����� ������
