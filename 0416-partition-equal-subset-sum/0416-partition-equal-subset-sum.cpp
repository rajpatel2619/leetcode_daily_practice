class Solution {
public:
    bool func(int ind, vector<int>&nums, int sum, vector<vector<int>> &dp){
        if(ind==0){
            return sum==0||sum==nums[0];
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool ntake = func(ind-1, nums, sum, dp);
        bool take = false;
        if (nums[ind] <= sum) {
            take = func(ind - 1, nums, sum - nums[ind], dp);
        }
        return dp[ind][sum] = take|ntake;

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return func(n-1, nums, sum/2, dp);
    }
};