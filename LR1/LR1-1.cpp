#include <iostream>
using namespace std;

int power(int, int);

int main()
{
    int base, exponent;

    cout << "Введите число: ";
    cin >> base;

    cout << "Введите степень: ";
    cin >> exponent;

    int result = power(base, exponent);

    cout << base << " в степени " << exponent << " равно " << result << endl;

    return 0;
}

int power(int x, int n)
{
    int i, p = 1;
    for (i = 1; i <= n; i++)
        p *= x;
    return p;
}