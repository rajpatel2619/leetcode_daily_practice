class Solution {
public:
    void func(int ind, vector<int>& nums, vector<int> &path, vector<vector<int>>&res, int target){
        
            if(target == 0){
                res.push_back(path);
            return;}
        
        if(target<0) return;
        for(int i=ind;i<nums.size();i++){
            path.push_back(nums[i]);
            func(i, nums, path, res, target-nums[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>path;
        func(0, candidates, path, res, target);
        return res;
    }
};