#include <iostream>

int main(void)
{
    int arr[] = {2, 5, -8, 1, 4, -6, 3, -5, -9, 13, 0, 4, 9};
    int mini, maxi;
    int n = sizeof(arr) / sizeof(int);
    int i = 0, t;
    mini = i;
    maxi = i;
    for (i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;

    for (i = 0; i < n - 1; i++)
    {
        mini = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[mini])
                mini = j;
        t = arr[i];
        arr[i] = arr[mini];
        arr[mini] = t;
    }
    for (i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
    return 0;
}