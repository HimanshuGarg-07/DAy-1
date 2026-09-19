#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string normalizeCode(string raw)
{
    // Remove leading and trailing spaces
    raw = raw.substr(
        raw.find_first_not_of(" "),
        raw.find_last_not_of(" ") - raw.find_first_not_of(" ") + 1
    );

    // Convert first 3 characters to uppercase
    for (int i = 0; i < 3 && i < raw.length(); i++)
    {
        raw[i] = toupper(raw[i]);
    }

    return raw;
}

string validateAndFormat(string code)
{
    // Check length
    if (code.length() != 13)
    {
        return "Invalid: wrong length";
    }

    // Check first 3 characters are letters
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(code[i]))
        {
            return "Invalid: publisher code must be 3 letters";
        }
    }

    // Check remaining 10 characters are digits
    for (int i = 3; i < 13; i++)
    {
        if (!isdigit(code[i]))
        {
            return "Invalid: body must contain only digits";
        }
    }

    string publisher = code.substr(0, 3);
    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    string result = "[" + publisher + "] YEAR: " +
                    year + " | CATALOG: " +
                    catalog;

    return result;
}

int main()
{
    string rawCode;

    cout << "Enter ISBN-style code: ";
    getline(cin, rawCode);

    string normalized = normalizeCode(rawCode);

    cout << validateAndFormat(normalized) << endl;

    return 0;
}