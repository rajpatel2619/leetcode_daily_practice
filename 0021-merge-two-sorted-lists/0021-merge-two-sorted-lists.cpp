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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        if(list1->val>list2->val)
            return mergeTwoLists(list2, list1);
        ListNode* first = list1->next;
        ListNode* prev = list1;
        ListNode* second = list2;
        while(first && second){
            if(first->val<=second->val){
                if(first->next == NULL){
                    first->next = second;
                    break;}
                else
                first = first->next;
                prev = prev->next;
                }
            else{
                prev->next = second;
                prev = second;
                second = second->next;
                prev->next = first;
            }
        }
        return list1;
    }
};