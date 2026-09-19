#include <iostream>
#include <string>

using namespace std;

char findFirstNonRepeatingChar(string text)
{
    int frequency[256] = {0};

    // Count frequency of every character
    for (int i = 0; i < text.length(); i++)
    {
        frequency[(unsigned char)text[i]]++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < text.length(); i++)
    {
        if (frequency[(unsigned char)text[i]] == 1)
        {
            return text[i];
        }
    }

    return '\0';
}

int main()
{
    string text;

    cout << "===== FIRST NON-REPEATING CHARACTER =====" << endl;

    cout << "Enter a string: ";
    getline(cin, text);

    char result = findFirstNonRepeatingChar(text);

    if (result != '\0')
    {
        cout << "First non-repeating character: "
             << result << endl;
    }
    else
    {
        cout << "No non-repeating character found." << endl;
    }

    return 0;
}