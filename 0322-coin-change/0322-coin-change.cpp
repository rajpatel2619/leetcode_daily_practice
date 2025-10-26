class Solution {
public:
    int func(int ind, vector<int> &nums, int tar, vector<vector<int>> &dp){
        if(ind==0){
            if(tar%nums[ind]==0) return tar/nums[ind];
            return 1e8;
        }
        if(dp[ind][tar]!=-1) return dp[ind][tar];
        int ans = func(ind-1, nums, tar, dp);
        if(tar>=nums[ind]){
            ans = min(ans, 1+func(ind, nums, tar-nums[ind], dp));
        }
        return dp[ind][tar] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = func(n-1, coins, amount, dp);
        if(ans>=1e8) return -1;
        return ans;
    }
};