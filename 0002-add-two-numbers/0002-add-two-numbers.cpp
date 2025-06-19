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
        int carry = 0;
        ListNode* head = l1;
        ListNode* prev;
        while(l1 and l2){
            int temp = l1->val + l2->val + carry;
            l1->val = temp%10;
            carry = (temp>=10)?1:0;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int temp = l1->val + carry;
            l1->val = temp%10;
            carry = (temp>=10)?1:0;
            prev = l1;
            l1 = l1->next;
        }
        prev->next = l2;
        while(l2){
            int temp = l2->val + carry;
            l2->val = temp%10;
            carry = (temp>=10)?1:0;
            prev = l2;
            l2 = l2->next;
        }
        if(carry) prev->next = new ListNode(carry);
        return head;
    }
};