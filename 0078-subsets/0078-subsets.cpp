class Solution {
public:
    void func(int ind, vector<int> &nums, vector<int>&path, vector<vector<int>>&res){
        if(ind==-1){
            res.push_back(path);
            return;
        }
        func(ind-1, nums, path, res);
        path.push_back(nums[ind]);
        func(ind-1, nums, path, res);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        func(nums.size()-1, nums, path, res);
        return res;
    }
};