#include <iostream>
#include <string>

using namespace std;

class Employee
{
public:
    string empName;
    double salary;

    static string companyName;
    static int employeeCount;

    Employee(string empName, double salary)
    {
        this->empName = empName;
        this->salary = salary;

        employeeCount++;
    }

    static void printCompanyInfo()
    {
        cout << companyName << endl;
        cout << "Employees on record: "
             << employeeCount << endl;
    }
};

// Definition of static variables
string Employee::companyName =
    "Bright Horizon Technologies";

int Employee::employeeCount = 0;

int main()
{
    Employee employee1("Ravi", 50000);
    Employee employee2("Anitha", 60000);
    Employee employee3("Karthik", 55000);

    Employee::printCompanyInfo();

    return 0;
}