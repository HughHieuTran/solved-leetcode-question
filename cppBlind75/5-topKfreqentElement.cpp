#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        for (int i : nums)
        {
            m[i]++;
        }

        vector<int, int> v(n + 1);
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v[it->second] = it->first;
        }

        vector<int> result;
        for (int i = n; i >= 0; i--)
        {
            if (result.size() > k)
                break;
            if (!v[i].empty())
            {
                result.push_back(v[i]);
            }
        }
        return result;
    }
};