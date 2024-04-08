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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (s.size() > 0 || curr != NULL)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            k--;
            if (k == 0)
            {
                return curr->val;
            }
            curr = curr->right;
        }
        return -1;
    }
    int kthSmallest2(TreeNode *root, int k)
    {
        int result = 0;
        inorder(root, k, result);
        return result;
    }

private:
    void inorder(TreeNode *root, int &k, int &result)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0)
        {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};

int main()
{
    TreeNode *tna = new TreeNode(1);
    tna->left = new TreeNode(2);
    tna->right = new TreeNode(3);
    

    Solution so;

    cout << so.kthSmallest(tna, 4) << endl;
}