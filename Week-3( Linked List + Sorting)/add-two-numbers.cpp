/* # Approach
 We simulate addition of digits using a carry. A dummy node is used to simplify the list construction.
 We loop through both lists, adding values and carry, and create new nodes accordingly.

 # Complexity
 Time complexity:
 O(max(n, m)) — One pass through the longer list.
 Space complexity: 
 O(max(n, m)) — New list stores the result.*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* l3 = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry > 0){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            l3->next = new ListNode(sum % 10);
            l3 = l3->next;
        }
        return dummy->next;
    }
};
