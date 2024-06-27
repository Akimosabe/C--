#include "Stroka.h"
#include <iostream>

int main() {
    // Создание объектов класса Stroka
    Stroka s1("Hello");
    Stroka s2("Hello");

    // Вывод исходных строк
    std::cout << "s1: ";
    s1.vyvod();
    std::cout << std::endl;

    std::cout << "s2: ";
    s2.vyvod();
    std::cout << std::endl;

    // Проверка оператора ==
    if (s1 == s2) {
        std::cout << "s1 и s2 равны" << std::endl;
    } else {
        std::cout << "s1 и s2 не равны" << std::endl;
    }

    // Проверка оператора +
    Stroka s3 = s1 + s2;
    std::cout << "Результат конкатенации s1 и s2: ";
    s3.vyvod();
    std::cout << std::endl;

    return 0;
}