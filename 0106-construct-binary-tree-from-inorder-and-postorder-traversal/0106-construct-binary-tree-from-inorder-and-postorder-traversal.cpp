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
    TreeNode* build(vector<int> &inorder, vector<int>&postorder, int inStart, int inEnd, int &postInd, unordered_map<int, int> &rootInfo){
        if(inStart>inEnd) return nullptr;
        int rval = postorder[postInd--];
        TreeNode* root = new TreeNode(rval);
        root->right = build(inorder, postorder, rootInfo[rval]+1, inEnd, postInd, rootInfo);
        root->left = build(inorder, postorder, inStart, rootInfo[rval]-1, postInd, rootInfo);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int pind = n-1;
        unordered_map<int, int> rootInfo;
        for(int i=0;i<n;i++){
            rootInfo[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, n-1, pind, rootInfo);
    }
};