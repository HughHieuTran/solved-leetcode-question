#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int maxCount = 0;
        int left = 0;
        int right = 0;
        int result = 0;
        vector<int> arr(26);
        while (right < s.size())
        {
            arr[s[right] - 'A']++;
            maxCount = max(maxCount, arr[s[right] - 'A']);
            if (right - left + 1 + maxCount < k)
            {
                arr[s[left] - 'a']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};