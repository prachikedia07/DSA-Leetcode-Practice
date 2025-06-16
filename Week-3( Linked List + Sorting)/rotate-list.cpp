/*# Approach
-Edge Case Check
-Find Length of the List
-Make the List Circular
-Find the New Head
-Break the Circle
-Set the node just before the new head’s next to NULL.

# Complexity
- Time complexity:
  O(n)
- Space complexity:
  O(1) */

# Code
```cpp []
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int n = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            n++;
        }
        tail->next = head;
        k = k % n;
        int StepToNewHead = n - k;
        ListNode* newTail = tail;
        while(StepToNewHead--){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};
```
