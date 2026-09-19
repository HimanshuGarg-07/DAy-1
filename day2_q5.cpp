#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string normalizeReference(string raw)
{
    // Remove leading and trailing spaces
    raw = raw.substr(raw.find_first_not_of(" "),
                     raw.find_last_not_of(" ") - raw.find_first_not_of(" ") + 1);

    // Convert first 3 characters to uppercase
    for (int i = 0; i < 3 && i < raw.length(); i++)
    {
        raw[i] = toupper(raw[i]);
    }

    return raw;
}

string validateAndFormat(string reference)
{
    // Check length
    if (reference.length() != 14)
    {
        return "Invalid: wrong length";
    }

    // Check first 3 characters are letters
    for (int i = 0; i < 3; i++)
    {
        if (!isalpha(reference[i]))
        {
            return "Invalid: bank code must be 3 letters";
        }
    }

    // Check remaining 11 characters are digits
    for (int i = 3; i < 14; i++)
    {
        if (!isdigit(reference[i]))
        {
            return "Invalid: body must contain only digits";
        }
    }

    string bankCode = reference.substr(0, 3);
    string date = reference.substr(3, 6);
    string sequence = reference.substr(9, 5);

    string formattedDate = date.substr(0, 2) + "/" +
                           date.substr(2, 2) + "/" +
                           date.substr(4, 2);

    string result = "[" + bankCode + "] DATE: " +
                    formattedDate + " | SEQ: " +
                    sequence;

    return result;
}

int main()
{
    string rawReference;

    cout << "Enter transaction reference: ";
    getline(cin, rawReference);

    string normalized = normalizeReference(rawReference);

    cout << validateAndFormat(normalized) << endl;

    return 0;
}