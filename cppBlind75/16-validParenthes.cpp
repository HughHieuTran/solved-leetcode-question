#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> vec;

        for (char c : s)
        {
            switch (c)
            {
            case '{':
            case '[':
            case '(':
                vec.push_back(c);
                break;
            case '}':
                if (vec.size()==0 || vec.back() != '{')
                {
                    return false;
                }
                vec.pop_back();
                break;
            case ']':
                if (vec.size()==0 || vec.back() != '[')
                {
                    return false;
                }
                vec.pop_back();
                break;
            case ')':
                if (vec.size()==0 ||vec.back() != '(')
                {
                    return false;
                }
                vec.pop_back();
                break;
            default:
                break;
            }
        }

        return vec.size() == 0;
    }
};

int main()
{
    Solution so;
    cout << so.isValid("[]");
}