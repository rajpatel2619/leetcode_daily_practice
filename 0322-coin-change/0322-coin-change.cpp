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
    int coinChange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        // base case
        for(int j=0;j<=target;++j){
            if(j%nums[0]==0) dp[0][j] = j/nums[0];
            else dp[0][j] = 1e8;
        }
        // main code
        for(int i=1;i<n;i++){
            for(int j = 1;j<=target;++j){
                int ans = dp[i-1][j];
                if(nums[i]<=j)
                    ans = min(ans, 1+dp[i][j-nums[i]]);
                dp[i][j] = ans;
            }
        }
        return dp[n-1][target]>=1e8?-1:dp[n-1][target];
    }
};