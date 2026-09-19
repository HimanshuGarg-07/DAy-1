#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void countVowelsAndConsonants(string text)
{
    int vowels = 0;
    int consonants = 0;

    for (int i = 0; i < text.length(); i++)
    {
        char ch = tolower(text[i]);

        if (ch == 'a' || ch == 'e' || ch == 'i' ||
            ch == 'o' || ch == 'u')
        {
            vowels++;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            consonants++;
        }
    }

    cout << "Vowels: " << vowels
         << " | Consonants: " << consonants << endl;
}

int main()
{
    string text;

    cout << "Enter book title: ";
    getline(cin, text);

    countVowelsAndConsonants(text);

    return 0;
}