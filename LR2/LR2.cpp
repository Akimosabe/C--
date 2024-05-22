#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define N 5
using namespace std;

void showMatrix(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << setw(8) << setprecision(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Минимум
float minMatrix(float matrix[N][N])
{
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// Максимум
float maxMatrix(float matrix[N][N])
{
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Максимум в нижнетреугольной части матрицы
float maxTriangleDown(float matrix[N][N])
{
    float maxVal = matrix[1][0];
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Максимум в верхнетреугольной части матрицы
float maxTriangleUp(float matrix[N][N])
{
    float maxVal = matrix[0][1];
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// Минимум в нижнетреугольной части матрицы
float minTriangdleDown(float matrix[N][N])
{
    float minVal = matrix[1][0];
    for (int i = 2; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// Минимум в верхнетреугольной части матрицы
float minTriangleUp(float matrix[N][N])
{
    float minVal = matrix[0][1];
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (matrix[i][j] < minVal)
            {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// Минимум на главной диагонали матрицы
float minMainDiagonal(float matrix[N][N])
{
    float minVal = matrix[0][0];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][i] < minVal)
        {
            minVal = matrix[i][i];
        }
    }
    return minVal;
}

// Максимум на главной диагонали матрицы
float maxMainDiagonal(float matrix[N][N])
{
    float maxVal = matrix[0][0];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][i] > maxVal)
        {
            maxVal = matrix[i][i];
        }
    }
    return maxVal;
}

// Минимум на второстепенной диагонали матрицы
float minSucDia(float matrix[N][N])
{
    float minVal = matrix[0][N - 1];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][N - 1 - i] < minVal)
        {
            minVal = matrix[i][N - 1 - i];
        }
    }
    return minVal;
}

// Максимум на второстепенной диагонали матрицы
float maxSecDia(float matrix[N][N])
{
    float maxVal = matrix[0][N - 1];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][N - 1 - i] > maxVal)
        {
            maxVal = matrix[i][N - 1 - i];
        }
    }
    return maxVal;
}

// Среднеарефметическое
float aaverage(float matrix[N][N])
{
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum / (N * N);
}

// Среднеарефметическое в нижнетреугольной части матрицы
float averageDownTriangle(float matrix[N][N])
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

// Среднеарефметическое в верхнетреугольной части матрицы
float averageUpTiangle(float matrix[N][N])
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

//  Сумма строк
float rowSum(float matrix[N][N], int row)
{
    float sum = 0;
    for (int j = 0; j < N; j++)
    {
        sum += matrix[row][j];
    }
    return sum;
}

//  Сумма столбцов
float columnSum(float matrix[N][N], int column)
{
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += matrix[i][column];
    }
    return sum;
}

// Минимальные значения строк
float minRow(float matrix[N][N], int row)
{
    float minVal = matrix[row][0];
    for (int j = 1; j < N; j++)
    {
        if (matrix[row][j] < minVal)
        {
            minVal = matrix[row][j];
        }
    }
    return minVal;
}

//  Минимальные значения столбцов
float minColum(float matrix[N][N], int column)
{
    float minVal = matrix[0][column];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][column] < minVal)
        {
            minVal = matrix[i][column];
        }
    }
    return minVal;
}

//  Максимальные значение строк
float maxRow(float matrix[N][N], int row)
{
    float maxVal = matrix[row][0];
    for (int j = 1; j < N; j++)
    {
        if (matrix[row][j] > maxVal)
        {
            maxVal = matrix[row][j];
        }
    }
    return maxVal;
}

//  Максимальные значения столбцов
float maxColum(float matrix[N][N], int column)
{
    float maxVal = matrix[0][column];
    for (int i = 1; i < N; i++)
    {
        if (matrix[i][column] > maxVal)
        {
            maxVal = matrix[i][column];
        }
    }
    return maxVal;
}
// Среднеарефметическое строк
float averageRow(float matrix[N][N], int row)
{
    float sum = 0;
    for (int j = 0; j < N; j++)
    {
        sum += matrix[row][j];
    }
    return sum / N;
}

// Среднеарефметическое столбцов
float averageColumn(float matrix[N][N], int column)
{
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += matrix[i][column];
    }
    return sum / N;
}

// Сумма нижнетреугольной части матрицы
float sumDownTriangle(float matrix[N][N])
{
    float sum = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Сумма верхнетреугольной части матрицы
float sumUpTriangle(float matrix[N][N])
{
    float sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Элемент, наиболее блищкий по значению к среднеарифмет
float ClosestToAverage(float matrix[N][N])
{
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += matrix[i][j];
            count++;
        }
    }
    float average = sum / count;
    float closestValue = matrix[0][0];
    float minDifference = abs(matrix[0][0] - average);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float difference = abs(matrix[i][j] - average);
            if (difference < minDifference)
            {
                minDifference = difference;
                closestValue = matrix[i][j];
            }
        }
    }
    return closestValue;
}

int main()
{
    float m[N][N];

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = rand() / 10.0f;
        }
    }

    cout << "Матрица:" << endl;
    showMatrix(m);

    cout << "Минимум: " << minMatrix(m) << endl;
    cout << "Максимум: " << maxMatrix(m) << endl;

    cout << "Максимум в нижнетреугольной части: " << maxTriangleDown(m) << endl;
    cout << "Максимум в верхнетреугольной части: " << maxTriangleUp(m) << endl;

    cout << "Минимум в нижнетреугольной части: " << minTriangdleDown(m) << endl;
    cout << "Минимум в верхнетреугольной части: " << minTriangleUp(m) << endl;

    cout << "Максимум на главной диагонали: " << maxMainDiagonal(m) << endl;
    cout << "Минимум на главной диагонали: " << minMainDiagonal(m) << endl;

    cout << "Максимум на второстепенной диагонали: " << maxSecDia(m) << endl;
    cout << "Минимум на второстепенной диагонали: " << minSucDia(m) << endl;

    cout << "Среднеарифметическое: " << aaverage(m) << endl;
    cout << "Среднеарифметическое в верхнетреугольной части: " << averageUpTiangle(m) << endl;
    cout << "Среднеарифметическое в нижнетреугольной части: " << averageDownTriangle(m) << endl;

    cout << "Сумма элементов столбца: " << columnSum(m, 1) << endl;
    cout << "Сумма элементов строки: " << rowSum(m, 1) << endl;

    cout << "Минимум в столбце: " << minColum(m, 1) << endl;
    cout << "Минимум в строке: " << minRow(m, 1) << endl;

    cout << "Максимум в столбце: " << maxColum(m, 1) << endl;
    cout << "Максимум в строке: " << maxRow(m, 1) << endl;

    cout << "Среднеарифметическое строки: " << averageRow(m, 1) << endl;
    cout << "Среднеарифметическое столбца: " << averageColumn(m, 1) << endl;

    cout << "Сумма нижнетреугольной части: " << sumDownTriangle(m) << endl;
    cout << "Сумма верхнетреугольной части: " << sumUpTriangle(m) << endl;

    cout << "Элемент, наиболее близкий к среднеарифметическому: " << ClosestToAverage(m) << endl;

    return 0;
}
