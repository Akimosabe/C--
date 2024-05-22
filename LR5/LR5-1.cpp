#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename;
    cout << "Введите имя файла: "; // Text.txt
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Файл " << filename << " не открыт" << endl;
        return 1;
    }

    cout << inFile.rdbuf();

    return 0;
}