#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> result(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            //                 i / 2      i % 2
            result[i] = result[i >> 1] + (i & 1);
        }

        return result;
    }
    vector<int> countBits2(int n)
    {
        vector<int> v;
        for (int i = 0; i <= n; i++)
        {
            v.push_back(hammingWeight(i));
        }
        return v;
    }
    int hammingWeight(int n)
    {
        int result = 0;
        while (n > 0)
        {
            if (n & 1)
            {
                result++;
            }
            n = (n >> 1);
        }
        return result;
    }
};