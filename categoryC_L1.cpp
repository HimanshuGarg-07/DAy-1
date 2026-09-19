#include <iostream>

using namespace std;

void twoSum(int nums[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "[" << i << ", " << j << "]" << endl;
                return;
            }
        }
    }
}

int main()
{
    int n;
    int target;

    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target: ";
    cin >> target;

    twoSum(nums, n, target);

    return 0;
}