#include <iostream>
#include <math.h>

int main(){

    int a = 1;
    int b = 5000;

    a = (int)ceil(sqrt(a));
    b = (int)floor(sqrt(b));

    std::cout << b - a << std::endl;

    return 0;
}