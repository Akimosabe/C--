#include "Stroka.h"
#include <cstring>
#include <iostream>


Stroka::Stroka(const char* string) {
    std::strncpy(str, string, 79); 
    str[79] = '\0'; 
}


Stroka::Stroka(const Stroka& s) {
    std::strcpy(str, s.str);
}


Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        std::strcpy(str, s.str);
    }
    return *this;
}


Stroka Stroka::operator+(const Stroka& s) const {
    Stroka result(*this); 
    std::strncat(result.str, s.str, sizeof(result.str) - std::strlen(result.str) - 1);
    return result; 
}


bool Stroka::operator==(const Stroka& s) const {
    return (std::strcmp(str, s.str) == 0); 
}


int Stroka::dlina() const {
    return std::strlen(str); 
}


void Stroka::vvod() {
    std::cin.getline(str, sizeof(str)); 
}


void Stroka::vyvod() const {
    std::cout << str; 
}