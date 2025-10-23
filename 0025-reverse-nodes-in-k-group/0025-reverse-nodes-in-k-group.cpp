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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp=temp->next;
        }

        int grps = len/k;
        ListNode* prevHead = nullptr;
        ListNode* currHead = head;
        ListNode* ansNode = nullptr;
        for(int i=0;i<grps;i++){
            //
            ListNode* prev = NULL;
            ListNode* curr = currHead;
            ListNode* nxt = nullptr;
            for(int j=0;j<k;j++){
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            //
            if(!prevHead) ansNode = prev;
            else prevHead->next = prev;
            prevHead = currHead;
            currHead = curr;
        }
        prevHead->next = currHead;
        return ansNode;
    }
};