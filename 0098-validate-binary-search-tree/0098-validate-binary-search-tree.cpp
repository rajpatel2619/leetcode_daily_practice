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
    long long prev = -1e10;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        if(!isValidBST(root->left))
            return false;

        if(root->val>prev)
            prev = root->val;
        else return false;

        
        return isValidBST(root->right);

    }
};