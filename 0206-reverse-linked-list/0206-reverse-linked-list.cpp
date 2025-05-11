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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* prev = NULL;
        ListNode* nt = head->next;
        while(nt){
            head->next = prev;
            prev = head;
            head = nt;
            nt = nt->next;
        }
        head->next = prev;
        return head;

    }
};