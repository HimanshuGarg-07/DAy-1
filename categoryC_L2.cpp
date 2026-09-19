#include <iostream>

using namespace std;

int maxProfit(int prices[], int n)
{
    int lowestPrice = prices[0];
    int maxProfitValue = 0;

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < lowestPrice)
        {
            lowestPrice = prices[i];
        }

        int profit = prices[i] - lowestPrice;

        if (profit > maxProfitValue)
        {
            maxProfitValue = profit;
        }
    }

    return maxProfitValue;
}

int main()
{
    int n;

    cout << "Enter number of days: ";
    cin >> n;

    int prices[n];

    cout << "Enter stock prices: ";

    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Maximum Profit: "
         << maxProfit(prices, n) << endl;

    return 0;
}