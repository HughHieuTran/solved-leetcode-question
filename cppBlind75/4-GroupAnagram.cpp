#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (string str : strs)
        {
            m[getKey(str)].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            result.push_back(it->second);
        }
        return result;
    }

    string getKey(string word)
    {
        int a[26] = {0};
        for (int i = 0; i < word.length(); i++)
        {
            a[word[i] - 'a']++;
        }
        string result = "";
        for (int i = 0; i < 26; i++)
        {
            result.append(a[i] + "%");
        }
    }
};