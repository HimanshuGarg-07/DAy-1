#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 1. Iterative approach
bool isPalindromeIterative(string text)
{
    int left = 0;
    int right = text.length() - 1;

    while (left < right)
    {
        if (text[left] != text[right])
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

// 2. Recursive approach
bool isPalindromeRecursive(string text, int left, int right)
{
    if (left >= right)
    {
        return true;
    }

    if (text[left] != text[right])
    {
        return false;
    }

    return isPalindromeRecursive(text, left + 1, right - 1);
}

// 3. Array reversal approach
bool isPalindromeArrayReversal(string text)
{
    string reversed = text;

    reverse(reversed.begin(), reversed.end());

    return text == reversed;
}

int main()
{
    string text;

    cout << "===== PALINDROME CHECKER =====" << endl;

    cout << "Enter a word or short phrase: ";
    getline(cin, text);

    bool result1 = isPalindromeIterative(text);

    bool result2 = isPalindromeRecursive(
        text, 0, text.length() - 1
    );

    bool result3 = isPalindromeArrayReversal(text);

    cout << "\n===== RESULTS =====" << endl;

    cout << "Iterative Approach: ";
    cout << (result1 ? "Palindrome" : "Not Palindrome") << endl;

    cout << "Recursive Approach: ";
    cout << (result2 ? "Palindrome" : "Not Palindrome") << endl;

    cout << "Array Reversal Approach: ";
    cout << (result3 ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}