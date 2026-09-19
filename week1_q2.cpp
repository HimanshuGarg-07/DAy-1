#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void checkTypingAccuracy(string original, string typed)
{
    int matched = 0;
    int firstMismatch = -1;

    int total = original.length();

    for (int i = 0; i < total; i++)
    {
        if (original[i] == typed[i])
        {
            matched++;
        }
        else if (firstMismatch == -1)
        {
            firstMismatch = i;
        }
    }

    double accuracy = (matched * 100.0) / total;

    cout << fixed << setprecision(2);

    cout << "Matched: " << matched << "/" << total
         << " | Accuracy: " << accuracy << "%";

    if (firstMismatch == -1)
    {
        cout << " | No Mismatches" << endl;
    }
    else
    {
        cout << " | First Mismatch at position "
             << firstMismatch + 1
             << " ('" << original[firstMismatch]
             << "' vs '" << typed[firstMismatch]
             << "')" << endl;
    }
}

int main()
{
    string original;
    string typed;

    cout << "Enter original passage: ";
    getline(cin, original);

    cout << "Enter typed text: ";
    getline(cin, typed);

    checkTypingAccuracy(original, typed);

    return 0;
}