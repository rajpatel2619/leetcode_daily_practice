class Solution {
public:
    bool func(int ind, vector<int>& nums, vector<int>&dp){
        if(ind>=nums.size()) return false;
        if(ind==nums.size()-1) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind+1;i<=ind+nums[ind];i++){
            if(func(i, nums, dp))
                return true;
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return func(0, nums, dp);
    }
};