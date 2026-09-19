#include <iostream>
#include <iomanip>

using namespace std;

string getBmiStatus(double bmi)
{
    if (bmi < 18.5)
    {
        return "Underweight";
    }
    else if (bmi < 25)
    {
        return "Normal";
    }
    else if (bmi < 30)
    {
        return "Overweight";
    }
    else
    {
        return "Obese";
    }
}

void printWellnessReport(double heights[], double weights[], int n)
{
    cout << "\n===== BMI WELLNESS REPORT =====" << endl;

    cout << left
         << setw(10) << "Person"
         << setw(12) << "Height"
         << setw(12) << "Weight"
         << setw(10) << "BMI"
         << setw(15) << "Status"
         << endl;

    for (int i = 0; i < n; i++)
    {
        double bmi = weights[i] / (heights[i] * heights[i]);

        cout << left
             << setw(10) << i + 1
             << setw(12) << heights[i]
             << setw(12) << weights[i]
             << setw(10) << fixed << setprecision(2) << bmi
             << setw(15) << getBmiStatus(bmi)
             << endl;
    }
}

int main()
{
    const int n = 10;

    double heights[n];
    double weights[n];

    cout << "===== BMI CALCULATOR =====" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nPerson " << i + 1 << endl;

        cout << "Enter height in meters: ";
        cin >> heights[i];

        cout << "Enter weight in kg: ";
        cin >> weights[i];
    }

    printWellnessReport(heights, weights, n);

    return 0;
}