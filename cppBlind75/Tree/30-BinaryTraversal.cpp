/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> q;
        q.push(root);

        while (q.size() > 0)
        {
            vector<int> curr;
            int sizeNow = q.size();
            for (int i = 0; i < sizeNow; i++)
            {
                curr.push_back(q.front()->val);
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
            }

            result.push_back(curr);
        }
        return result;
    }
};

int main()
{
    TreeNode *tna = new TreeNode(1);
    tna->left = new TreeNode(2);
    tna->right = new TreeNode(3);
    tna->left->left = new TreeNode(4);
    tna->left->right = new TreeNode(5);
    tna->right->left = new TreeNode(6);
    tna->right->right = new TreeNode(7);

    Solution so;
    so.levelOrder(tna);
}