#include <iostream>
#include <string>

using namespace std;

string reverseCustomerName(string customerName)
{
    string reversed = "";

    for (int i = customerName.length() - 1; i >= 0; i--)
    {
        reversed += customerName[i];
    }

    return reversed;
}

int main()
{
    string customerName;

    cout << "===== REVERSE CUSTOMER NAME =====" << endl;

    cout << "Enter customer name: ";
    getline(cin, customerName);

    string reversedName = reverseCustomerName(customerName);

    cout << "\nOriginal Name : " << customerName << endl;
    cout << "Reversed Name : " << reversedName << endl;

    return 0;
}