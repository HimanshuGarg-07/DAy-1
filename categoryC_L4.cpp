#include <iostream>

using namespace std;

void mergeSortedArrays(int arr1[], int n1, int arr2[], int n2)
{
    int result[n1 + n2];

    int i = 0;
    int j = 0;
    int k = 0;

    // Compare elements from both arrays
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            result[k] = arr1[i];
            i++;
        }
        else
        {
            result[k] = arr2[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of arr1
    while (i < n1)
    {
        result[k] = arr1[i];
        i++;
        k++;
    }

    // Copy remaining elements of arr2
    while (j < n2)
    {
        result[k] = arr2[j];
        j++;
        k++;
    }

    // Print merged array
    cout << "Merged Array: ";

    for (int x = 0; x < n1 + n2; x++)
    {
        cout << result[x] << " ";
    }

    cout << endl;
}

int main()
{
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    int arr1[n1];

    cout << "Enter first sorted array: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;

    int arr2[n2];

    cout << "Enter second sorted array: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    mergeSortedArrays(arr1, n1, arr2, n2);

    return 0;
}