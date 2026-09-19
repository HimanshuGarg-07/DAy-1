#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void parseInventoryRecord(string csvLine)
{
    string fields[3];
    string field;
    stringstream ss(csvLine);

    int count = 0;

    while (getline(ss, field, ','))
    {
        if (count < 3)
        {
            fields[count] = field;
        }

        count++;
    }

    if (count != 3)
    {
        cout << "Invalid Record" << endl;
        return;
    }

    cout << "Product: " << fields[0]
         << " | SKU: " << fields[1]
         << " | Qty: " << fields[2] << endl;
}

int main()
{
    string csvLine;

    cout << "Enter inventory record: ";
    getline(cin, csvLine);

    parseInventoryRecord(csvLine);

    return 0;
}