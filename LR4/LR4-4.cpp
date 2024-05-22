#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int dlina(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char *kopir(const char *src)
{
    int len = dlina(src);
    char *dest = (char *)malloc(len + 1);
    if (dest != nullptr)
    {
        strcpy(dest, src);
    }
    return dest;
}

int sravn(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

char *konkat(const char *str1, const char *str2)
{
    int len1 = dlina(str1);
    int len2 = dlina(str2);
    char *result = (char *)malloc(len1 + len2 + 1);
    if (result != nullptr)
    {
        strcpy(result, str1);
        strcat(result, str2);
    }
    return result;
}

int main()
{
    const char *strings[] = {
        "You", "can", "fool", "all", "of", "the", "people", "some", "of", "the", "time,", "and", "some", "of", "the", "people", "all", "of", "the", "time,", "but", "you", "can't", "fool", "all", "of", "the", "people", "all", "of", "the", "time."};

    for (int i = 0; i < sizeof(strings) / sizeof(strings[0]); ++i)
    {
        const char *currentString = strings[i];
        cout << "Строка " << i + 1 << ": " << currentString << endl;

        cout << "Длина строки: " << dlina(currentString) << endl;

        char *copiedString = kopir(currentString);
        cout << "Копирование: " << copiedString << endl;
        free(copiedString);

        if (i > 0)
        {
            cout << "Сравнение: " << sravn(currentString, strings[i - 1]) << endl;
        }

        if (i < sizeof(strings) / sizeof(strings[0]) - 1)
        {
            char *concatenatedString = konkat(currentString, strings[i + 1]);
            cout << "Конкатенация: " << concatenatedString << endl;
            free(concatenatedString);
        }

        cout << endl;
    }

    return 0;
}