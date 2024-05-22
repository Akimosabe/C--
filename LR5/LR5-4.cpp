#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void fileto(const string &inputFilename, const string &outputFilename)
{
    ifstream inFile(inputFilename);
    if (!inFile)
    {
        cerr << "Ошибка открытия файла: " << inputFilename << endl;
        return;
    }

    ofstream outFile(outputFilename);
    if (!outFile)
    {
        cerr << "Ошибка создания файла: " << outputFilename << endl;
        inFile.close();
        return;
    }

    string line;
    string pageNumber;

    while (getline(inFile, line))
    {
        if (line.find("|") == 0 && line.find("|", 1) != string::npos)
        {
            if (!pageNumber.empty())
            {
                outFile << pageNumber << endl;
            }
            pageNumber = line.substr(1, line.find("|", 1) - 1);
        }
        else
        {
            outFile << line << endl;
        }
    }

    if (!pageNumber.empty())
    {
        outFile << pageNumber << endl;
    }

    cout << "Результат сохранен в файле: " << outputFilename << endl;

    inFile.close();
    outFile.close();
}

int main()
{
    string inputFilename, outputFilename;

    cout << "Введите имя файла: ";
    getline(cin, inputFilename);

    cout << "Введите имя файла для сохранения результатов: ";
    getline(cin, outputFilename);

    fileto(inputFilename, outputFilename);

    return 0;
}