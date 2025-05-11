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
    TreeNode* build(vector<int>&preorder, int inStart, int inEnd, int &preInd, unordered_map<int, int>&mp){
            if(inStart>inEnd) return nullptr;
            int rval = preorder[preInd++];
            TreeNode* root = new TreeNode(rval);
            root->left = build(preorder, inStart, mp[rval]-1, preInd, mp);
            root->right = build(preorder, mp[rval]+1, inEnd, preInd, mp);
            return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int pInd = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        return build(preorder, 0, n-1, pInd, mp);
    }
};