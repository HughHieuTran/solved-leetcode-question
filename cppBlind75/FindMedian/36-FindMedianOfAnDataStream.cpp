#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lower.size() == 0)
        {
            lower.push(num);
            return;
        }
        if (lower.size() > higher.size())
        {
            if (lower.top() > num)
            {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
            else
            {
                higher.push(num);
            }
        }
        else
        {
            if (higher.top() < num)
            {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
            else
            {
                lower.push(num);
            }
        }
    }

    double findMedian()
    {
        double result = 0.0;
        if (lower.size() == higher.size())
        {
            result = (lower.top() + higher.top()) / 2;
        }
        else
        {
            result = lower.size() > higher.size() ? lower.top() : higher.top();
        }
        return result;
    }
};
