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
    void inorder(TreeNode* root, vector<int> &res){
        stack<TreeNode*> st;
        while(root or !st.empty()){
            // going deeper in left
            while(root){
                st.push(root);
                root = root->left;
            }

            // inorder val
            root = st.top();
            st.pop();
            res.emplace_back(root->val);

            // go one step right
            root = root->right;
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for(int i=1;i<res.size();++i)
            if(res[i]<=res[i-1])
                return false;
        return true;
    }
};