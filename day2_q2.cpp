#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void parseStudentRecord(string csvLine)
{
    string fields[3];
    stringstream ss(csvLine);

    string field;
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

    cout << "Name: " << fields[0]
         << " | Roll No: " << fields[1]
         << " | Dept: " << fields[2] << endl;
}

int main()
{
    string csvLine;

    cout << "Enter student record: ";
    getline(cin, csvLine);

    parseStudentRecord(csvLine);

    return 0;
}