#include <iostream>

using namespace std;

bool containsDuplicate(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
            {
                return true;
            }
        }
    }

    return false;
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

    if (containsDuplicate(nums, n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}