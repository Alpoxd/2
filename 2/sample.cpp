#include <iostream> 
#include <cstdlib>
#include <vector>
#include "vector.h"
#include "matrix.h"

void main(void) {
    std::vector<float> input1 = { 20.2, 38.7, -21.32, -3.1, 6.43 };
    std::vector<float> input2 = { -32.32, 9995.42, 10000.2, 2, 3.212 };
    std::vector<float> input3 = { 1, 2, 3.2 }, input4 = { 1, 2 };
    std::vector<std::vector<float>> dinput = { { 1.5, -2.2, 20 }, { 4, 5, 6 }, { 7, 28, 9 } };
    std::vector<std::vector<float>> dinput2 = { { 1.5, -2.2 }, { 4, 5, 6 }, { 7, 28, 9 } };
    matrix dv1(dinput);
    matrix dv5(dinput2);
    dv5.print();
    matrix dv2 = dv1;
    dv1.print();
    dv2.print();
    dv1 = dv2;
    matrix dv3;
    dv3.print();
    dv3 = dv2;
    dv3.print();
    matrix dv4(2, 3);
    dv4.print();
}