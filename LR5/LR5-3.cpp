#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

void searchString(const string &filename, const string &substring)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        throw runtime_error("Ошибка открытия файла: " + filename);
    }

    string outputFilename = "Result.txt";
    ofstream outFile(outputFilename);
    if (!outFile)
    {
        throw runtime_error("Ошибка создания файла для записи результатов: " + outputFilename);
    }

    string line;
    size_t lineNumber = 0;

    while (getline(inFile, line))
    {
        lineNumber++;
        size_t position = line.find(substring);
        if (position != string::npos)
        {
            outFile << "Строка " << lineNumber << ": Найдено в позиции " << position << endl;
            outFile << line << endl;
        }
    }

    cout << "Результаты поиска сохранены в файле: " << outputFilename << endl;

    inFile.close();
    outFile.close();
}

int main()
{
    string filename;
    cout << "Введите имя файла для поиска: "; // Text.txt
    cin >> filename;

    string substring;
    cout << "Введите строку для поиска: ";
    cin >> substring;

    try
    {
        searchString(filename, substring);
    }
    catch (const exception &e)
    {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}