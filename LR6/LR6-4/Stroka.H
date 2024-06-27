#ifndef STROKA_H
#define STROKA_H

#include <iostream>

class Stroka {
private:
    char* str; 

public:
    
    Stroka(const char* string = ""); 
    Stroka(const Stroka& s); 
    ~Stroka(); 

    
    Stroka& operator=(const Stroka& s); 
    Stroka operator+(const Stroka& s) const; 
    bool operator==(const Stroka& s) const; 

    
    static int my_strlen(const char* str);
    static char* my_strcpy(char* dest, const char* src);
    static int my_strcmp(const char* str1, const char* str2);
    static char* my_strcat(char* dest, const char* src);

    
    int dlina() const; 
    void vvod(); 
    void vyvod() const; 
};

#endif 