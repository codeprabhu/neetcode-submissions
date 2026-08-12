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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        for(auto list: lists)
        {
            if(!list)
                continue;
            pq.push({list->val, list});
        }
            
        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;
        while(!pq.empty())
        {
            auto [val, node] = pq.top();
            pq.pop();

            head->next = node;
            head = head->next;

            if(!node->next)
                continue;
                
            node = node->next;
            pq.push({node->val, node});
        }

        return dummy->next;
    }
};
