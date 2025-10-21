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
    int maxi = INT_MIN;
    int func(TreeNode* root){
        if(!root) return 0;
        int lsum = func(root->left);
        int rsum = func(root->right);
        int sum = root->val+lsum+rsum;
        maxi = max(maxi, sum);
        return max(0, root->val+max(lsum, rsum));
    }
    int maxPathSum(TreeNode* root) {
        maxi = max(maxi, root->val+func(root->left)+func(root->right));
        return maxi;
    }
};