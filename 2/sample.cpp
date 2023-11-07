#include <iostream> 
#include <cstdlib>
#include <vector>
#include "dfraction.h" 
#include "vector.h"

void main(void) {
    setlocale(LC_ALL, "Ru");
    std::vector<float> input1 = { 20.2, 38.7, -21.32, -3.1, 6.43 };
    std::vector<float> input2 = { -32.32, 43.42, 10000.2, 2, 3.212 };
    std::vector<float> input3 = { 1 }, input4 = { 1 };
    vector v1(input1.size());
    vector v2(input2.size());
    vector v3(input3.size());
    vector v4(input4.size());
    v3 == v4 ? printf("T") : printf("F");
    vector v5(v4);
    //v1[6] = v1[2];
    //vector v3(input3.size());
    for (int i = 0; i < v1.size(); i++) v1[i] = input1[i];
    printf("\nv1:\n\n");
    v1.print();  
    for (int i = 0; i < v2.size(); i++) v2[i] = input2[i];
    printf("\nv2:\n\n");
    v2.print();
    vector sum = v1 + v2;
    printf("\nsum:\n\n");
    sum.print();
    vector add = v1 += v2;
    printf("\nadd:\n\n");
    add.print();
    vector dif = v1 - v2;
    printf("\ndif:\n\n");
    dif.print();
    v1 = v2;
    printf("\n============================\n\n");
    v1.print();
    printf("============================\n\n");
    v2.print();
    printf("============================\n");
}