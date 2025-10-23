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
        ListNode* dummy = new ListNode(0);
        ListNode* dummyHead = dummy;
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;
        for(auto head:lists)
            if(head) pq.push({head->val, head});
        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();
            if(node.second->next) pq.push({node.second->next->val, node.second->next});
            dummy->next = node.second;
            dummy = dummy->next;
        }
        return dummyHead->next;

    }
};