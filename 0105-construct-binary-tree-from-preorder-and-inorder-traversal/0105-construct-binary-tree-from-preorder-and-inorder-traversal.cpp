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
    TreeNode* build(int pl, int pr, vector<int> &pre, int il, int ir, vector<int> &in){
        if(pl>pr or il>ir) return NULL;
        TreeNode* root = new TreeNode(pre[pl]);
        int i = il;
        while(in[i]!=root->val) i++;
        int count = i-il;
        root->left = build(pl+1, pl+count, pre, il, i-1, in);
        root->right = build(pl+count+1, pr, pre, i+1, ir, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(0, n-1, preorder, 0, n-1, inorder);
    }
};