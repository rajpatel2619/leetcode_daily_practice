/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
//     github check..
public:
    void deleteNode(ListNode* node) {
       *node = *node->next;
    }
};