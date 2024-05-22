#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void emptyChar(const string &filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Файл " << filename << " не удалось открыть" << endl;
        return;
    }

    int emptyCount = 0;
    int nonEmptyCount = 0;
    char ch;

    while (inFile.get(ch))
    {
        if (isspace(ch) || !isprint(ch))
        { //
            emptyCount++;
        }
        else
        {
            nonEmptyCount++;
        }
    }

    cout << "Пустые символы: " << emptyCount << endl;
    cout << "Непустые символы: " << nonEmptyCount << endl;
}

int main()
{
    string filename;
    cout << "Введите имя файла: ";
    cin >> filename;

    emptyChar(filename);

    return 0;
}