#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string maskPhoneNumber(string phone)
{
    if (phone.length() != 10)
    {
        return "Invalid phone number";
    }

    for (int i = 0; i < phone.length(); i++)
    {
        if (!isdigit(phone[i]))
        {
            return "Invalid phone number";
        }
    }

    string result = "XXXXXX";

    result += "-";
    result += phone.substr(6, 4);

    return result;
}

int main()
{
    string phone;

    cout << "Enter phone number: ";
    getline(cin, phone);

    cout << maskPhoneNumber(phone) << endl;

    return 0;
}