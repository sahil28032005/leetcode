/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nulldptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool result;
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            int left = getHeight(root->left);
            int right = getHeight(root->right);
            return left > right ? left + 1 : right + 1;
        }
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            result = isBalanced(root->left);
            if (!result)
            {
                return false;
            }
            result = isBalanced(root->right);
            if (!result)
            {
                return false;
            }
            int balFact = (getHeight(root->left) - 1) - (getHeight(root->right) - 1);
            if (balFact > 1 || balFact < -1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        //    return result;
    }
};