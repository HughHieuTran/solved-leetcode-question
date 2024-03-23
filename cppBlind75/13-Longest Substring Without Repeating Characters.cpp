#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> set;
        int result = 0, left = 0, right = 0;
        while (right < s.size())
        {
            while (set.count(s[right]) > 0)
            {
                set.erase(s[left]);
                left++;
            }
            result = max(result, right - left + 1);
            set.insert(s[right]);
            right++;
        }
        return result;
    }
};