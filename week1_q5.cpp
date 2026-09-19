#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void classifyWordLengths(string review)
{
    string word;

    int shortCount = 0;
    int mediumCount = 0;
    int longCount = 0;

    stringstream ss(review);

    while (ss >> word)
    {
        int length = word.length();

        if (length >= 1 && length <= 4)
        {
            shortCount++;
        }
        else if (length >= 5 && length <= 8)
        {
            mediumCount++;
        }
        else
        {
            longCount++;
        }
    }

    cout << "Short: " << shortCount << endl;
    cout << "Medium: " << mediumCount << endl;
    cout << "Long: " << longCount << endl;
}

int main()
{
    string review;

    cout << "Enter movie review: ";
    getline(cin, review);

    classifyWordLengths(review);

    return 0;
}