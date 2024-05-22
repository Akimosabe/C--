#include <iostream>
#include <cstring>
using namespace std;

// длина строки 1
int dlina1(char *str)
{
    return strlen(str);
}

// длина строки 2
int dlina2(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

// длина строки 3
int dlina3(char *str)
{
    char *ptr = str;
    while (*ptr)
    {
        ptr++;
    }
    return ptr - str;
}

// копирование строки 1
void kopir(char *dest, char *src)
{
    strcpy(dest, src);
}

// копирование строки 2
int sravn(char *str1, char *str2)
{
    return strcmp(str1, str2);
}

// конкатеция
void konkat(char *dest, char *src)
{
    strcat(dest, src);
}

int main()
{
    char str1[] = "qwerty";
    char str2[] = "1234567890";

    // использование функций длины строки
    cout << "Длина первой строки: " << dlina1(str1) << ", длина второй строки: " << dlina1(str2) << endl;
    cout << "Длина первой строки: " << dlina2(str1) << ", длина второй строки: " << dlina2(str2) << endl;
    cout << "Длина первой строки: " << dlina3(str1) << ", длина второй строки: " << dlina3(str2) << endl;

    char copiedStr[20];
    kopir(copiedStr, str1);
    cout << "Копирование: " << copiedStr << endl;

    cout << "Сравнение: " << sravn(str1, str2) << endl;

    konkat(str1, str2);
    cout << "Конкатенация: " << str1 << endl;

    return 0;
}