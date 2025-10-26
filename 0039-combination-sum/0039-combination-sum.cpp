class Solution {
public:
    void func(int ind, vector<int> &nums, int tar, vector<int>&path, vector<vector<int>> &res){
        if(ind==-1){
            if(tar==0)
                res.push_back(path);
            return;
        }
        func(ind-1, nums, tar, path, res);
        if(nums[ind]<=tar){
            path.push_back(nums[ind]);
            func(ind, nums, tar-nums[ind], path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int tar) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        func(nums.size()-1, nums, tar, path, res);
        return res;
    }
};