class Solution {
public:
    bool func(int ind, vector<int> &nums, int target, vector<vector<int>> &dp){
        int n = nums.size();
        if(ind==n){
            return target==0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];

        bool take = false, ntake = false;
        if(nums[ind]<=target)
            take = func(ind+1, nums, target-nums[ind], dp);
        ntake = func(ind+1, nums, target, dp);
        return dp[ind][target] =  take|ntake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        sum/=2;
        // solve
        vector<vector<int>> dp(nums.size(), vector<int>(sum+1, -1)); 
        return func(0, nums, sum, dp);
    }
};