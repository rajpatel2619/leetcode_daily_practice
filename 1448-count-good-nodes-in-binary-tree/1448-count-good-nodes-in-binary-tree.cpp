/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int count = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node.first->val>=node.second) count++;
            if(node.first->left) q.push({node.first->left, max(node.second, node.first->left->val)});
            if(node.first->right) q.push({node.first->right, max(node.second, node.first->right->val)});
        }
        return count;
    }
};