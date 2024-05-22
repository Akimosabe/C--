#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void textencrypt(const string &inputFile, const string &key, const string &encfile)
{
    ifstream fin(inputFile);
    if (!fin)
    {
        cerr << "Ошибка при открытии файла: " << inputFile << endl;
        return;
    }

    ofstream fout(encfile);
    if (!fout)
    {
        cerr << "Ошибка при создании файла: " << encfile << endl;
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

    cout << "Результат сохранен в " << encfile << endl;

    fin.close();
    fout.close();
}

int main()
{

    string inputFile = "Text.txt";
    string key = "bebe";
    string encfile = "Enc"; //шифровали
    string decfile = "Dec.txt"; //расшифровали

    textencrypt(inputFile, key, encfile);
    textencrypt(encfile, key, decfile);


    return 0;
}