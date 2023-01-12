#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    int X1 = 10;
    int X2 = 20;
    std::cout << "BEFORE SWAPPING" << std::endl;
    std::cout << "X1 is " << X1 << std::endl;
    std::cout << "X2 is " << X2 << std::endl;
    swap(&X1, &X2);
    std::cout << "AFTER SWAPPING" << std::endl;
    std::cout << "X1 is " << X1 << std::endl;
    std::cout << "X2 is " << X2 << std::endl;
    return 0;
}