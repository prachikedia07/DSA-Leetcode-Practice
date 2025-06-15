/* # Approach
 We traverse the linked list using two pointers. If adjacent nodes have the same value,
 we skip the duplicate node by updating the link. This ensures only distinct elements remain.

 # Complexity
 Time complexity: 
 O(n) — Each node is visited once.
 Space complexity:
 O(1) — No extra space is used.*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return 0;

        ListNode* p = head;
        ListNode* q = head->next;

        while (p->next != NULL) {
            if (p->val == q->val) {
                p->next = q->next;
                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
        }
        return head;
    }
};
