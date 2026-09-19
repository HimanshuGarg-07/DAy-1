#include <iostream>

using namespace std;

void productExceptSelf(int nums[], int n)
{
    int answer[n];

    // Product of all elements to the left
    int leftProduct = 1;

    for (int i = 0; i < n; i++)
    {
        answer[i] = leftProduct;
        leftProduct = leftProduct * nums[i];
    }

    // Product of all elements to the right
    int rightProduct = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] = answer[i] * rightProduct;
        rightProduct = rightProduct * nums[i];
    }

    cout << "Output: [";

    for (int i = 0; i < n; i++)
    {
        cout << answer[i];

        if (i < n - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
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

    productExceptSelf(nums, n);

    return 0;
}