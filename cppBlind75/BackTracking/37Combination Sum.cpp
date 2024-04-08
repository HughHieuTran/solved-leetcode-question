#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> curr;
        back_track(candidates, target, 0, curr, result);
        return result;
    }

    void back_track(vector<int> &candidates, int target, int index, vector<int> &curr, vector<vector<int>> &res)
    {
        if (index >= candidates.size() || target < 0)
            return;
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        curr.push_back(candidates[index]);
        back_track(candidates, target - candidates[index], index, curr, res);
        curr.pop_back();
        back_track(candidates, target, index + 1, curr, res);
    }
};