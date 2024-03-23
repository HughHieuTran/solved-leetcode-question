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
    }

    string getKey(string word)
    {
        int arr[26] = {0};
        for (char c : word)
        {
            arr[c - 'a']++;
        }
        string result = "";
        for (int i : arr)
        {
            result.append(to_string(i) + "%");
        }
        return result;
    }
};