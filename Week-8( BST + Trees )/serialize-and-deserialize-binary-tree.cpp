/*
## ❓ Problem Statement
Serialization is the process of converting a data structure (like a binary tree) into a string so that it can be stored or transmitted. Deserialization is the reverse process — converting the string back into the original tree.
Design an algorithm to:
- Serialize a binary tree into a string.
- Deserialize the string back into the original binary tree.
You can design your own encoding/decoding strategy. It just needs to be consistent and reversible.
---

## 🌳 Example

Given the binary tree:
    1
   / \
  2   3
     / \
    4   5
The serialized string (level-order) would be:
"1,2,3,null,null,4,5,null,null,null,null,"
This represents:
- Root = 1
- 1's children: 2 (left), 3 (right)
- 2 has no children → `null,null`
- 3 has children 4 and 5
- 4 and 5 are leaf nodes → `null,null` for each
---

## 🧠 Approach
### ✅ Serialization (Level Order / BFS):
- Traverse the tree level by level using a queue.
- For each node:
  - If it's `null`, append `"null,"` to the result string.
  - Otherwise, append the node value and push its left and right children to the queue.

### ✅ Deserialization:
- Split the string by commas to get all node values in a list.
- The first value is the root.
- Use a queue to reconstruct the tree:
  - For each node from the queue:
    - Take the next two values from the list for its left and right children.
    - If they're not `"null"`, create new nodes and add them to the queue.
---

## ⏱️ Complexity

- **Time complexity:** 
  O(n)  
- **Space complexity:** 
  O(n)  
---
*/
## 🧾 Code

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == NULL) {
                s.append("null,");
            } else {
                s.append(to_string(curr->val) + ',');
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        vector<string> nodes;
        stringstream s(data);
        string token;
        while (getline(s, token, ',')) {
            nodes.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            if (nodes[i] != "null") {
                TreeNode* leftnode = new TreeNode(stoi(nodes[i]));
                curr->left = leftnode;
                q.push(leftnode);
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                TreeNode* rightnode = new TreeNode(stoi(nodes[i]));
                curr->right = rightnode;
                q.push(rightnode);
            }
            i++;
        }

        return root;
    }
};

// Usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



