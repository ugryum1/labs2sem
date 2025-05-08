#include <iostream>
#include "containers/myvector.h"
#include "polynom/term.h"
#include "polynom/polynomial.h"

int main() {
    /*
    Term<Polynomial> term1, term2;

    std::cout << "Введите первый терм." << std::endl;
    std::cin >> term1;
    std::cout << "Введите второй терм." << std::endl;
    std::cin >> term2;

    Term<Polynomial> term = term1 + term2;
    std::cout << "Сумма " << term1 << " и " << term2 << ": " << term << std::endl;
    */

    Polynomial polynom1;
    std::cout << "Введите первый полином polymom1." << std::endl;
    std::cin >> polynom1;
    std::cout << "Polynom: "<< polynom1 << std::endl << std::endl;

    Polynomial poly;
    std::cout << "Введите второй полином poly." << std::endl;
    std::cin >> poly;
    std::cout << "Poly: " << poly << std::endl;

    std::cout << std::endl;
    Polynomial poly1 = polynom1 + poly;
    std::cout << "polynom1 + poly = " << poly1 << std::endl;

    Polynomial poly2 = polynom1 * poly;
    std::cout << "polynom1 * poly = " << poly2 << std::endl;

    /*
    Polynomial polynom2(polynom1);
    std::cout << std::endl << "polynom2(polynom1): " << polynom2 << std::endl;

    polynom2 = polynom1;
    std::cout << "polynom2 = polynom1: " << polynom2 << std::endl;

    polynom2 += polynom1;
    std::cout << "polynom2 += polynom1: " << polynom2 << std::endl;

    Polynomial polynom3(term1);
    polynom2 *= polynom3;
    std::cout << "polynom2 *= polynom3, где polynom3 = term1: " << polynom2 << std::endl;

    std::cout << std::endl << "Итак, сейчас:" << std::endl;
    std::cout << "polynom1: " << polynom1 << std::endl;
    std::cout << "polynom2: " << polynom2 << std::endl;
    std::cout << "polynom3: " << polynom3 << std::endl << std::endl;

    Polynomial polynom4 = polynom1 + polynom2;
    std::cout << "polynom4 = polynom1 + polynom2: " << polynom4 << std::endl;
    polynom4.setOrder(-1);
    std::cout << "polynom4 (вывод по возрастанию степеней): " << polynom4 << std::endl << std::endl;

    Polynomial polynom5 = polynom1 * polynom2;
    std::cout << "polynom4 = polynom1 * polynom2: " << polynom5 << std::endl;
    polynom5.setOrder(-1);
    std::cout << "polynom5 (вывод по возрастанию степеней): " << polynom5 << std::endl;
    */

    return 0;
}
