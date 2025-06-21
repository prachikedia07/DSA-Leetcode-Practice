/*# Approach
-Use a dummy node before head to simplify edge cases (like reversing from the head).
-Traverse to the node just before position left — call it prev.
-Reverse the sublist from left to right.
-Reconnect the reversed part with the rest of the list.
# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)    */
  
  
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        for(int i = 1; i<left ;i++){
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        ListNode* next = NULL;
       for (int i = 0; i < right - left; ++i) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
```
