// Given an unsorted array of integers nums,
// return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for (auto& num : set) {
            if (set.count(num - 1) == 0) {
                int length = 1;
                while (set.count(num + length) > 0) {
                    length++;
                }
                longest = max(length, longest);
            }
        }
        return longest;
    }
};