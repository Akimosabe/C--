#include <iostream>
#include <cstring> 

class MyString {
private:
    char* str;

public:
    // Конструкторы
    MyString() : str(nullptr) {} 
    MyString(const char* s); 
    MyString(const MyString& other); 

    // Деструктор
    ~MyString();

    // Перегруженные операторы
    MyString& operator=(const MyString& other); // Оператор присваивания
    MyString operator+(const MyString& other) const; // Оператор сцепления
    bool operator==(const MyString& other) const; // Оператор сравнения на равенство


    int length() const; 
    void input(); 
    void output() const; 
};

MyString::MyString(const char* s) {
    if (s) {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    } else {
        str = nullptr;
    }
}

MyString::MyString(const MyString& other) {
    if (other.str) {
        int len = strlen(other.str);
        str = new char[len + 1];
        strcpy(str, other.str);
    } else {
        str = nullptr;
    }
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str; 
        if (other.str) {
            int len = strlen(other.str);
            str = new char[len + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result;

    if (str && other.str) {
        int len1 = strlen(str);
        int len2 = strlen(other.str);
        int totalLen = len1 + len2;

        result.str = new char[totalLen + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
    } else if (str) {
        result = *this;
    } else if (other.str) {
        result = other;
    }

    return result;
}

bool MyString::operator==(const MyString& other) const {
    return (strcmp(str, other.str) == 0);
}

int MyString::length() const {
    return (str ? strlen(str) : 0);
}

void MyString::input() {
    char buffer[100]; 
    std::cin.getline(buffer, 100);
    *this = MyString(buffer);
}

void MyString::output() const {
    if (str) {
        std::cout << str;
    }
}

int main() {
    MyString s1("Hello");
    MyString s2("World");

    MyString s3 = s1 + s2; // Сцепление строк
    s3.output(); // Вывод: HelloWorld

    if (s1 == s2) {
        std::cout << "s1 and s2 are equal\n";
    } else {
        std::cout << "s1 and s2 are not equal\n";
    }

    std::cout << "Length of s1: " << s1.length() << std::endl; 

    MyString s4;
    std::cout << "Enter a string: ";
    s4.input(); 
    s4.output(); 

    return 0;
}