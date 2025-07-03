// #Approach
// For example,
//           1
//         ↙   ↘
//      2         3
//     ↙
//   4

// Call stack looks like:

// maxDepth(1)
//   ├── maxDepth(2)
//   │     └── maxDepth(4) → returns 1
//   └── maxDepth(3) → returns 1

// → node 2 returns 1 + max(1, 0) = 2  
// → node 1 returns 1 + max(2, 1) = 3


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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
         int lh = maxDepth(root->left);
         int rh = maxDepth(root->right);

         return 1 + max(lh,rh);
    }
};
```
