#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text;
    getline(cin, text, '#');

    string processed;
    for (char c : text)
    {
        if (isalnum(c) || c == '_')
        {
            processed += tolower(c);
        }
        else
        {
            processed += ' ';
        }
    }

    unordered_map<string, int> wordFreq;
    string word;
    for (char c : processed)
    {
        if (c != ' ')
        {
            word += c;
            if (word.length() > 15)
            {
                word = word.substr(0, 15);
            }
        }
        else if (!word.empty())
        {
            wordFreq[word]++;
            word.clear();
        }
    }
    if (!word.empty())
    {
        wordFreq[word]++;
    }

    cout << wordFreq.size() << endl;

    vector<pair<string, int>> wordList(wordFreq.begin(), wordFreq.end());
    sort(wordList.begin(), wordList.end(), [](const pair<string, int> &a, const pair<string, int> &b)
         {
        if (a.second != b.second) {
            return a.second > b.second;
        }
        return a.first < b.first; });

    int topCount = max(1, static_cast<int>(wordList.size() * 0.1));
    for (int i = 0; i < topCount; ++i)
    {
        cout << wordList[i].second << ":" << wordList[i].first << endl;
    }

    return 0;
}