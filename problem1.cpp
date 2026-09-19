#include <iostream>
#include <iomanip>

using namespace std;

void applyMultipliers(double playerScores[], int captainIndex, int viceCaptainIndex)
{
    playerScores[captainIndex] = playerScores[captainIndex] * 2;
    playerScores[viceCaptainIndex] = playerScores[viceCaptainIndex] * 1.5;
}

int main()
{
    double scores[] = {40, 55, 30, 62};

    applyMultipliers(scores, 1, 3);

    cout << "[";

    for (int i = 0; i < 4; i++)
    {
        cout << fixed << setprecision(1) << scores[i];

        if (i < 3)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}