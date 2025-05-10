class Solution {
public:
    int func(int ind, int prev, vector<int> &nums, vector<vector<int>>& dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int ntake = 0 + func(ind+1, prev, nums, dp);
        int take = 0;
        if(prev==-1 || ind!=prev+1)
            take = nums[ind]+func(ind+1, ind, nums, dp);
        return dp[ind][prev+1] =  max(take, ntake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return func(0, -1, nums, dp);    
    }
};