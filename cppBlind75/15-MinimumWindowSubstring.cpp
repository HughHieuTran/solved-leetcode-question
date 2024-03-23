#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> needChars;
        for (char c : t)
        {
            needChars[c]++;
        }
        int left = 0;
        int right = 0;
        int minLength = INT_MAX;
        int minLeft = 0;
        int need = t.size();
        while (right < s.size())
        {
            if (needChars[s[right]] > 0)
            {
                need--;
            }
            needChars[s[right]]--;
            right++;

            while (need == 0)
            {
                if (right - left < minLength)
                {
                    minLeft = left;
                    minLength = right - left;
                }
                needChars[s[left]]++;
                if (needChars[s[left]] > 0)
                {
                    need++;
                }
                left++;
            }
        }

        if (minLength != INT_MAX)
        {
            return s.substr(minLeft, minLength);
        }
        return "";
    }
};
