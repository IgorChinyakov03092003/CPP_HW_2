#include <iostream>

using namespace std;

int main()
{
    int M;
    int N;
    std::cin >> M;
    std::cin >> N;
    if ((M < 0) || (N < 0)) {
        std::cout << "Error!" << std::endl;
    }
    else {
        int* nums1 = new int[M + N];
        int* nums2 = new int[N];
        for (int i = 0; i < M + N; i++) {
            nums1[i] = 0;
        }
        for (int i = 0; i < N; i++) {
            nums2[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            std::cin >> nums1[i];
        }
        for (int i = 0; i < N; i++) {
            std::cin >> nums2[i];
        }
        int p = 0;
        for (int j = M; j < M + N; j++) {
            nums1[j] = nums2[p];
            p++;
            int k = j;
            while (nums1[k] < nums1[k - 1]) {
                std::swap(nums1[k], nums1[k - 1]); //сдвиг элементов как в сортировке вставками
                k -= 1;
                if (k == 0) {
                    break;
                }
            }
        }
        for (int i = 0; i < M + N; i++) {
            std::cout << nums1[i] << " ";
        }
        delete[] nums1;
        delete[] nums2;
    }
    return 0;
}