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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is pointing to mid
        ListNode* head2 = slow->next;
        slow->next = nullptr;

        ListNode* rhead = reverse(head2);
        ListNode* node =head;
        while(rhead){
            ListNode* temp = rhead;
            rhead=rhead->next;
            temp->next = node->next;
            node->next = temp;
            node = temp->next; 
        }
    }
};