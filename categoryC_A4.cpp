#include <iostream>
#include <unordered_map>

using namespace std;

int subarraySum(int nums[], int n, int k)
{
    unordered_map<int, int> prefixCount;

    prefixCount[0] = 1;

    int currentSum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum = currentSum + nums[i];

        int needed = currentSum - k;

        if (prefixCount.find(needed) != prefixCount.end())
        {
            count = count + prefixCount[needed];
        }

        prefixCount[currentSum]++;
    }

    return count;
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter k: ";
    cin >> k;

    cout << "Number of Subarrays: "
         << subarraySum(nums, n, k) << endl;

    return 0;
}