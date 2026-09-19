#include <iostream>

using namespace std;

void analyzeInventory(int sectionA[], int sectionB[], int n)
{
    int totalA = 0;
    int totalB = 0;

    int highestQuantity = sectionA[0];
    char highestSection = 'A';
    int highestIndex = 0;

    // Calculate totals for both sections
    for (int i = 0; i < n; i++)
    {
        totalA += sectionA[i];
        totalB += sectionB[i];
    }

    // Find highest quantity in Section A
    for (int i = 0; i < n; i++)
    {
        if (sectionA[i] > highestQuantity)
        {
            highestQuantity = sectionA[i];
            highestSection = 'A';
            highestIndex = i;
        }
    }

    // Find highest quantity in Section B
    for (int i = 0; i < n; i++)
    {
        if (sectionB[i] > highestQuantity)
        {
            highestQuantity = sectionB[i];
            highestSection = 'B';
            highestIndex = i;
        }
    }

    cout << "Section A Total: " << totalA << endl;
    cout << "Section B Total: " << totalB << endl;

    if (totalA == totalB)
    {
        cout << "Status: Balanced" << endl;
    }
    else
    {
        cout << "Status: Not Balanced" << endl;
    }

    cout << "Highest Quantity: " << highestQuantity
         << " (Section " << highestSection
         << ", Item " << highestIndex + 1 << ")" << endl;
}

int main()
{
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    int sectionA[n];
    int sectionB[n];

    cout << "Enter quantities for Section A:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> sectionA[i];
    }

    cout << "Enter quantities for Section B:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> sectionB[i];
    }

    analyzeInventory(sectionA, sectionB, n);

    return 0;
}