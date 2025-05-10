class Solution {
public:
    int func(int ind, int prev, vector<int>& nums, vector<vector<int>> &dp){
        int n = nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take = 0;
        if(prev==-1 || ind!=prev+1){
            take = nums[ind] + func(ind+1, ind, nums, dp);
        }
        int ntake = func(ind+1, prev, nums, dp);
        return dp[ind][prev+1] = max(take, ntake);
    }
    int rob2(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return func(0, -1, nums, dp);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<n;i++){
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob2(temp1), rob2(temp2));
    }
};