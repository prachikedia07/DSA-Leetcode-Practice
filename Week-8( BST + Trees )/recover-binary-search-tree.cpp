/*

## 🧠 Intuition & Flow

Do an inorder traversal and look for two nodes where the order is violated.

Keep track of:
- `prev` = previously visited node
- `first`, `middle`, `last` = pointers to wrong nodes

Two violation cases:
- Non-adjacent swapped nodes: swap `first` and `last`
- Adjacent swapped nodes: swap `first` and `middle`

---

## 🧠 Flow Diagram:

Inorder: `1 → 3 → 2 → 4`  
At 3 → 2: ❌

Detected:
- first = 3
- middle = 2

✅ Swap(3, 2)

---

## ✨ Approach

Use recursive inorder traversal to detect nodes violating BST property, then swap to fix.

---

## ⏱️ Complexity

- **Time complexity:** O(n)
- **Space complexity:** O(h) recursion stack

---
*/
## ✅ Code

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* first = NULL;
    TreeNode* middle = NULL;
    TreeNode* last = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* curr) {
        if (!curr) return;

        inorder(curr->left);

        if (prev && curr->val < prev->val) {
            if (!first) {
                first = prev;
                middle = curr;
            } else {
                last = curr;
            }
        }

        prev = curr;

        inorder(curr->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
