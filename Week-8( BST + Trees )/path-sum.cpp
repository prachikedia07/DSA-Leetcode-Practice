# Code
```cpp []
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        if (!root->right && !root->left && root->val == targetSum)
            return true;
        int remaining = targetSum - root->val;
        return (hasPathSum(root->right, remaining) ||
                hasPathSum(root->left, remaining));
    }
};
```
