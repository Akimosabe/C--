#include "Stroka.h"
#include "my_string_functions.h" 
#include <iostream>

int main() {
    
    Stroka s1("qwert"); 
    Stroka s3; 
    Stroka s4(s1); 
    Stroka s5; 

    
    std::cout << "Введите строку для объекта s3: ";
    s3.vvod(); 

    
    std::cout << "Содержимое объекта s3: ";
    s3.vyvod(); 
    std::cout << std::endl;

    
    s5 = s1 + s3 + s4; 

    
    std::cout << "Длина строки s5 = " << s5.dlina() << std::endl;

    
    std::cout << "Содержимое строки s5: ";
    s5.vyvod();
    std::cout << std::endl;

    
    if (s1 == s5) {
        std::cout << "Строки s1 и s5 равны" << std::endl;
    } else if (s1 == s4) {
        std::cout << "Строки s1 и s4 равны" << std::endl;
    }

    return 0;
}