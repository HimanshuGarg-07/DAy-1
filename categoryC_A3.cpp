#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(int nums[], int n)
{
    sort(nums, nums + n);

    vector<vector<int>> result;

    for (int i = 0; i < n - 2; i++)
    {
        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate left values
                while (left < right && nums[left] == nums[left + 1])
                {
                    left++;
                }

                // Skip duplicate right values
                while (left < right && nums[right] == nums[right - 1])
                {
                    right--;
                }

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return result;
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

    vector<vector<int>> result = threeSum(nums, n);

    cout << "Triplets: [";

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[" << result[i][0] << ", "
             << result[i][1] << ", "
             << result[i][2] << "]";

        if (i < result.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}