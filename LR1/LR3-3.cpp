#include <iostream>
using namespace std;

// int
pair<int, int> obmen1(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    return make_pair(x, y);
}

// int*
void obmen2(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// int&
void obmen3(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 2, b = 5;

    std::cout << "до обмена: a = " << a << " b = " << b << std::endl;

    // Вызов функции обмена с параметрами типа int
    tie(a, b) = obmen1(a, b);
    std::cout << "после обмена 1: a = " << a << " b =" << b << std::endl;

    // Вызов функции обмена с указателями
    obmen2(&a, &b);
    std::cout << "после обмена 2: a = " << a << " b =" << b << std::endl;

    // Вызов функции обмена с ссылками
    obmen3(a, b);
    std::cout << "после обмена 3: a = " << a << " b =" << b << std::endl;

    return 0;
}