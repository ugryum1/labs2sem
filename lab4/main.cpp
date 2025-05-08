#include <iostream>
#include "MyStackLib/MyStack.h"

template <typename DATA> void Multipliers(int n, MyStack<DATA> &stack) {
    if (n <= 1) {
        return;
    }

    // Делим на 2, пока число четное
    while (n % 2 == 0) {
        stack.push(2);
        n /= 2;
    }

    // Проверяем нечетные делители от 3 до sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            stack.push(i);
            n /= i;
        }
    }

    // Если после всех делений осталось простое число > 1
    if (n > 1) {
        stack.push(n);
    }
}

int main() {
    MyStack<int> stack, stack_2;

    int number;
    std::cout << "Введите число" << std::endl;
    std::cin >> number;

    Multipliers(std::abs(number), stack);

    std::cout << number << "=";
    std::cout << stack << std::endl;

	while (!stack.empty()) {
		int curr = stack.top_inf();
		stack.pop();
		stack_2.push(curr);
	}

    std::cout << number << "=";
    std::cout << stack_2 << std::endl;

    return 0;
}
