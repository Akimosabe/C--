#include <iostream>
#include <cstring>
#include <cstdlib> 
using namespace std;

int dlina1(const char* str) {
    return strlen(str);
}

int dlina2(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int dlina3(const char* str) {
    const char* ptr = str;
    while (*ptr) {
        ptr++;
    }
    return ptr - str;
}

char* kopir(const char* src) {
    int len = strlen(src);
    char* dest = (char*)malloc(len + 1); 
    if (dest != nullptr) {
        strcpy(dest, src);
    }
    return dest;
}

int sravn(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

char* konkat(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char* result = (char*)malloc(len1 + len2 + 1);
    if (result != nullptr) {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

int main() {
    char* str1 = (char*)malloc(100); 
    char* str2 = (char*)malloc(100); 

    if (str1 == nullptr || str2 == nullptr) {
        cout << "Ошибка выделения памяти!" << endl;
        return 1;
    }

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "Длина первой строки: " << dlina1(str1) << ", длина второй строки: " << dlina1(str2) << endl;
    cout << "Длина первой строки: " << dlina2(str1) << ", длина второй строки: " << dlina2(str2) << endl;
    cout << "Длина первой строки: " << dlina3(str1) << ", длина второй строки: " << dlina3(str2) << endl;

    char* copiedStr = kopir(str1);
    if (copiedStr != nullptr) {
        cout << "Копирование: " << copiedStr << endl;
        free(copiedStr); 
    }

    cout << "Сравнение: " << sravn(str1, str2) << endl;

    char* concatenatedStr = konkat(str1, str2);
    if (concatenatedStr != nullptr) {
        cout << "Конкатенация: " << concatenatedStr << endl;
        free(concatenatedStr);
    }

    free(str1);
    free(str2);

    return 0;
}