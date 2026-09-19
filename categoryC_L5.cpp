#include <iostream>

using namespace std;

void rotateArray(int nums[], int n, int k)
{
    k = k % n;

    int newArray[n];

    for (int i = 0; i < n; i++)
    {
        int newPosition = (i + k) % n;
        newArray[newPosition] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = newArray[i];
    }

    cout << "Rotated Array: ";

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
}

int main()
{
    int n;
    int k;

    cout << "Enter number of elements: ";
    cin >> n;

    int nums[n];

    cout << "Enter array elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter number of rotations: ";
    cin >> k;

    rotateArray(nums, n, k);

    return 0;
}