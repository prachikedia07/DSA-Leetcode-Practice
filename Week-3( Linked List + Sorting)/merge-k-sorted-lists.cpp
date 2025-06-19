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
struct compare{
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(int i = 0; i < lists.size() ; i++){
            if(lists[i])
            pq.push(lists[i]);
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next){
                pq.push(temp->next );
            }
        }
        return dummy.next;
    }
};
```
