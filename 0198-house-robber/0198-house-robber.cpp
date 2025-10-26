class Solution {
public:
    int func(int ind, vector<int> &dp, vector<int>& nums){
        if(ind<=0){
            if(ind==0) return nums[ind];
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        int ntake = func(ind-1, dp, nums);
        int take = nums[ind]+func(ind-2, dp, nums);

        return dp[ind] =  max(take, ntake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return func(n-1, dp, nums);
    }
};