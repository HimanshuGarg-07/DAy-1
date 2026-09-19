#include <iostream>

using namespace std;

int maxSubArray(int nums[], int n)
{
    int currentSum = nums[0];
    int maximumSum = nums[0];

    for (int i = 1; i < n; i++)
    {
        if (currentSum + nums[i] > nums[i])
        {
            currentSum = currentSum + nums[i];
        }
        else
        {
            currentSum = nums[i];
        }

        if (currentSum > maximumSum)
        {
            maximumSum = currentSum;
        }
    }

    return maximumSum;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Maximum Subarray Sum: "
         << maxSubArray(nums, n) << endl;

    return 0;
}