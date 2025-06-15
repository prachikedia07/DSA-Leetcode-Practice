/* # Approach
 We use slow and fast pointers. The fast pointer moves twice as fast as the slow one.
 When the fast one reaches the end, the slow one will be at the middle node.

 # Complexity
 Time complexity: 
  O(n) 
 Space complexity:
  O(1)*/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        while(q != NULL && q->next!= NULL ){
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
};
