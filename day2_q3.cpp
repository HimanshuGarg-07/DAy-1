#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string validateFileExtension(string filename)
{
    int dotPosition = filename.find_last_of('.');

    if (dotPosition == string::npos)
    {
        return "Rejected - invalid file type";
    }

    string extension = filename.substr(dotPosition + 1);

    for (int i = 0; i < extension.length(); i++)
    {
        extension[i] = tolower(extension[i]);
    }

    if (extension == "pdf" ||
        extension == "docx" ||
        extension == "zip")
    {
        return "Accepted";
    }

    return "Rejected - invalid file type";
}

int main()
{
    string filename;

    cout << "Enter filename: ";
    getline(cin, filename);

    cout << validateFileExtension(filename) << endl;

    return 0;
}