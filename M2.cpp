#include <iostream>

using namespace std;

class PayrollAccount
{
private:
    double basicSalary;
    double bonus;

public:
    PayrollAccount(double basicSalary)
    {
        if (basicSalary < 0)
        {
            cout << "Warning: Negative salary. Starting with 0." << endl;
            this->basicSalary = 0;
        }
        else
        {
            this->basicSalary = basicSalary;
        }

        bonus = 0;
    }

    void creditBonus(double amount)
    {
        if (amount <= 0)
        {
            cout << "Bonus rejected: invalid amount" << endl;
        }
        else
        {
            bonus = bonus + amount;
            cout << "Bonus credited: Rs " << amount << endl;
        }
    }

    void deductTax(double percent)
    {
        if (percent < 0 || percent > 100)
        {
            cout << "Tax rejected: invalid percentage" << endl;
        }
        else
        {
            basicSalary = basicSalary - (basicSalary * percent / 100);

            cout << "Tax deducted: "
                 << percent << "%" << endl;
        }
    }

    double getNetSalary()
    {
        return basicSalary + bonus;
    }
};

int main()
{
    PayrollAccount account(50000);

    account.creditBonus(5000);
    account.deductTax(10);

    cout << "Net salary: Rs "
         << account.getNetSalary() << endl;

    return 0;
}