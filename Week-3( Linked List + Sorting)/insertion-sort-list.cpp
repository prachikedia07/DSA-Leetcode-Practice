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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode dummy(0);
        ListNode* curr = head;
        while(curr){
            ListNode* prev = &dummy;
            ListNode* next = curr->next;
            while(prev->next != NULL && prev->next->val < curr->val){
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        return dummy.next;
    }
};
```
