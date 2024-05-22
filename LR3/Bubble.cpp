#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    int arr[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(int);

    // Неотсортированный массив
    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Отсортированный
    cout << "Сортировка пузырьком: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
