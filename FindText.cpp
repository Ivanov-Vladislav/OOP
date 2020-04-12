#include <iostream>
#include <functional>
#include <fstream>
#include <string>

using namespace std;

using FindStringCallback = function<void(int lineIndex, const string & line, size_t foundPos, string search)>;

bool FindStingInStream(
    ifstream& input,
    const string& search,
    const FindStringCallback& callback = FindStringCallback())
{
    string line;
    bool found = false;
    for (int lineIndex = 1; getline(input, line); ++lineIndex)
    {
        auto pos = line.find(search);
        if ((pos != string::npos) && (line.length() != 0) && (search != ""))
        {
            found = true;
            // Передаем в функцию обратного вызова информацию о
            // первом найденном вхождении подстроки
            if (callback)
            {
                callback(lineIndex, line, pos, search);
            }
        }
        else if ((pos != string::npos) && (line.length() == 0) && (search == ""))
        {
            found = true;
            if (callback)
            {
                callback(lineIndex, line, pos, search);
            }
        }
    }
    return found;
}

void PrintFoundLineIndex(int lineIndex, const string& line, size_t foundPos, string search)
{
    cout << lineIndex << "\t" << search << endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");

    if (argc != 3)
    {
        cout << "Invalid arguments count\n";
        cout << "FindText.exe <input.txt> <text to search>\n";
        return 1;
    }

    ifstream input;
    input.open(argv[1]);
    if (!input.is_open())
    {
        cout << "File \"" << argv[1] << "\" not open.";
        return 1;
    }

    string search = argv[2];
    if (!FindStingInStream(input, search, PrintFoundLineIndex))
    {
        cout << "No string found\n";
        return 1;
    }
    return 0;
}
