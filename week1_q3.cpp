#include <iostream>
#include <string>

using namespace std;

void findLongestStreak(string signalLog)
{
    int longestLength = 1;
    char longestColor = signalLog[0];

    int currentLength = 1;

    for (int i = 1; i < signalLog.length(); i++)
    {
        if (signalLog[i] == signalLog[i - 1])
        {
            currentLength++;
        }
        else
        {
            currentLength = 1;
        }

        if (currentLength > longestLength)
        {
            longestLength = currentLength;
            longestColor = signalLog[i];
        }
    }

    cout << "Longest Streak: '"
         << longestColor
         << "' repeated "
         << longestLength
         << " times" << endl;
}

int main()
{
    string signalLog;

    cout << "Enter signal log: ";
    cin >> signalLog;

    findLongestStreak(signalLog);

    return 0;
}