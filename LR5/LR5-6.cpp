#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void textencrypt(const string &inputFile, const string &key, const string &outputFile)
{
    ifstream fin(inputFile);
    if (!fin)
    {
        cerr << "Ошибка при открытии файла: " << inputFile << endl;
        return;
    }

    ofstream fout(outputFile);
    if (!fout)
    {
        cerr << "Ошибка при создании файла: " << outputFile << endl;
        fin.close();
        return;
    }

    char ch;
    size_t keyIndex = 0;
    while (fin.get(ch))
    {
        char encryptedChar = ch ^ key[keyIndex % key.length()];
        fout << encryptedChar;
        keyIndex++;
    }

    cout << "Результат сохранен в " << outputFile << endl;

    fin.close();
    fout.close();
}

int main()
{
    string inputFile, key, outputFile;

    cout << "Введите имя файла: ";
    cin >> inputFile;

    cout << "Введите ключ: "; // было введено bebe
    cin >> key;

    cout << "Введите имя файла для сохранения результатов: ";
    cin >> outputFile;

    textencrypt(inputFile, key, outputFile);

    return 0;
}