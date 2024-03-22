#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int arr[26] = {0};
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};