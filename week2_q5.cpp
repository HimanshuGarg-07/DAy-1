#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

void printFilteredWordFrequency(string feedback)
{
    // Convert text to lowercase
    for (int i = 0; i < feedback.length(); i++)
    {
        feedback[i] = tolower(feedback[i]);
    }

    // Remove punctuation
    for (int i = 0; i < feedback.length(); i++)
    {
        if (feedback[i] == '.' || feedback[i] == ',' ||
            feedback[i] == '!' || feedback[i] == '?' ||
            feedback[i] == ';' || feedback[i] == ':')
        {
            feedback[i] = ' ';
        }
    }

    // Stop words
    string stopWords[] = {
        "the", "was", "and", "a", "is", "of", "in"
    };

    map<string, int> frequency;

    string word;
    stringstream ss(feedback);

    while (ss >> word)
    {
        bool isStopWord = false;

        for (int i = 0; i < 7; i++)
        {
            if (word == stopWords[i])
            {
                isStopWord = true;
                break;
            }
        }

        if (!isStopWord)
        {
            frequency[word]++;
        }
    }

    // Move words into a vector
    vector<pair<string, int>> words(
        frequency.begin(), frequency.end()
    );

    // Sort by frequency in descending order
    sort(words.begin(), words.end(),
         [](pair<string, int> a, pair<string, int> b)
         {
             return a.second > b.second;
         });

    // Print result
    for (int i = 0; i < words.size(); i++)
    {
        cout << words[i].first
             << ": " << words[i].second << endl;
    }
}

int main()
{
    string feedback;

    cout << "Enter feedback: ";
    getline(cin, feedback);

    printFilteredWordFrequency(feedback);

    return 0;
}