#include <iostream>
#include <cstring>
#include "containers/myvector.h"
#include "printedEditions/printedEditions.h"

void print(MyVector<PrintedEdition*>& container) {
    std::cout << "Container:" << std::endl;
    for (int i = 0; i < container.getSize(); ++i) {
        container[i]->show();
    }
    std::cout << std::endl;
}

void remove(MyVector<PrintedEdition*>& container, int index) {
    int size = container.getSize();
    if (index < 0 || index >= size) {
        std::cout << "Invalid index for remove\n";
        return;
    }

    delete container[index];
    container.delete_element(index);
}

void clear(MyVector<PrintedEdition*>& container) {
    int size = container.getSize();
    for (int i = 0; i < size; ++i) {
        delete container[i];
    }

    while (container.getSize() > 0) {
        container.delete_element(0);
    }
}

int main() {
    MyVector<PrintedEdition*> container;

    container.add_element(new Book("The Great Gatsby", "F. Scott Fitzgerald", "Novel", 1925, 180));
    container.add_element(new Journal("National Geographic", "National Geographic Society", 256, 2023, 120));
    container.add_element(new Textbook("Advanced Mathematics", "John Doe", "Mathematics", 11, 2020, 350));

    // демонстрация работы функций
    print(container); // вывод всех элементов

    remove(container, 1); // удаляем журнал

    print(container); // вывод после удаления

    clear(container); // очищаем контейнер

    print(container); // вывод после очистки

    return 0;
}
