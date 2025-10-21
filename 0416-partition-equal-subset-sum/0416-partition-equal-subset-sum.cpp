class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        sum/=2;
        // solve
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        if(nums[0]<=sum)
            dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool ntake = dp[i-1][j];
                bool take = false;
                if(nums[i]<=j){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take or ntake;
            }
        }
        return dp[n-1][sum];
    }
};