#include "Stroka.h"
#include <cstring>
#include <iostream>


Stroka::Stroka(const char* string) {
    str = my_strcpy(new char[my_strlen(string) + 1], string); 
}


Stroka::Stroka(const Stroka& s) {
    str = my_strcpy(new char[s.dlina() + 1], s.str); 
}


Stroka::~Stroka() {
    delete[] str; 
}


Stroka& Stroka::operator=(const Stroka& s) {
    if (this != &s) {
        delete[] str; 
        str = my_strcpy(new char[s.dlina() + 1], s.str); 
    }
    return *this;
}


Stroka Stroka::operator+(const Stroka& s) const {
    char* temp = my_strcat(my_strcpy(new char[dlina() + s.dlina() + 1], str), s.str); 
    Stroka result(temp); 
    delete[] temp; 
    return result;
}


bool Stroka::operator==(const Stroka& s) const {
    return my_strcmp(str, s.str) == 0; 
}


int Stroka::dlina() const {
    return my_strlen(str); 
}


void Stroka::vvod() {
    char buffer[100]; 
    std::cin.getline(buffer, sizeof(buffer)); 
    *this = Stroka(buffer); 
}


void Stroka::vyvod() const {
    std::cout << str; 
}