#include <iostream>
#include <algorithm>
using namespace std;

bool N1N2Down(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int N1 = 1;
    int N2 = 9;

    if (N1 < 0 || N1 >= n || N2 < 0 || N2 >= n || N1 > N2)
    {
        cout << "Некорректный интервал" << endl;
        return 1;
    }

    sort(arr + N1, arr + N2 + 1, N1N2Down);

    cout << "Сортировка по убыванию с интервалом от индекса " << N1 << " до " << N2 << ": ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
