#include <iostream>

using namespace std;

void checkDuplicateSeats(int seatNumbers[], int n)
{
    bool duplicateFound = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (seatNumbers[i] == seatNumbers[j])
            {
                cout << "Duplicate Seat Number Found: "
                     << seatNumbers[i] << endl;

                duplicateFound = true;
            }
        }
    }

    if (!duplicateFound)
    {
        cout << "No Duplicate Seats Found" << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of seats: ";
    cin >> n;

    int seatNumbers[n];

    cout << "Enter seat numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> seatNumbers[i];
    }

    checkDuplicateSeats(seatNumbers, n);

    return 0;
}