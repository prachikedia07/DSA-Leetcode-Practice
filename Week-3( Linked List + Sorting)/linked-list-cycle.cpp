/*# Approach
We use **Floyd’s Cycle Detection Algorithm (Tortoise and Hare)**:
- We use two pointers: `slow` and `fast`.
- `slow` moves one step at a time, while `fast` moves two steps.
- If the list has a cycle, these two pointers will eventually meet.
- If `fast` or `fast->next` becomes `NULL`, it means there's no cycle.

This approach does **not use extra memory** and works in a **single pass**.

# Complexity
- Time complexity:  
  O(n)
- Space complexity:  
  O(1)*/
# Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
