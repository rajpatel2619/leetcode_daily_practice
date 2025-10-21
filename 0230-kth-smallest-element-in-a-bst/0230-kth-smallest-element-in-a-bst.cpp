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
    vector<int> inorder(TreeNode* root){
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr or !st.empty()){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            res.emplace_back(curr->val);

            curr = curr->right;
        }
        return res;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr =  inorder(root);
        return arr[k-1];
    }
};