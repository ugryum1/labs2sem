#include <iostream>
#include "mymath/mymath.h"
#include "myfact/myfact.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(10, 32) << std::endl;

    std::cout << "Также я умею считать факториал числа! 6!=";
    std::cout << myfact::fact(6) << std::endl;

    return 0;
}
