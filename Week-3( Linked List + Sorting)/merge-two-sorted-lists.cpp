/*# Approach
We use a dummy node to simplify list merging. A tail pointer is used to build the result list.
We iterate while both lists are non-empty, comparing current nodes and attaching the smaller one to the result.
At the end, we attach any remaining part of the non-empty list. -->

# Complexity
- Time complexity: 
O(n + m)
- Space complexity:
O(1)*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1 == NULL && list2 ==  NULL) return NULL;
        // if(list1 == NULL) return list2;
        // if(list2 == NULL) return list1;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                 tail->next  = list1;
                 list1 = list1->next; 
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    } 
};
