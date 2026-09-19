#include <iostream>
#include <string>

using namespace std;

string findMinMaxSpread(int scores[], int n)
{
    int minimum = scores[0];
    int maximum = scores[0];

    for (int i = 1; i < n; i++)
    {
        if (scores[i] < minimum)
        {
            minimum = scores[i];
        }

        if (scores[i] > maximum)
        {
            maximum = scores[i];
        }
    }

    int spread = maximum - minimum;

    return "Min: " + to_string(minimum)
         + " | Max: " + to_string(maximum)
         + " | Spread: " + to_string(spread);
}

int main()
{
    int scores[] = {45, 82, 79, 90, 33, 90, 61};

    int n = 7;

    cout << findMinMaxSpread(scores, n) << endl;

    return 0;
}