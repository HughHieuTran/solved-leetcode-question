#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int result = 0;
        while (left < right)
        {
            int volume = (right - left) * min(height[left], height[right]);
            result = max(result, volume);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }
};