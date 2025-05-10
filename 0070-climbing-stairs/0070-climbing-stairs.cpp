class Solution {
public:
    int func(int ind, int n, vector<int> &dp){
        if(ind==n) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int one = 0, two = 0;
        one = func(ind+1, n, dp);
        if(ind+2<=n)
            two = func(ind+2, n, dp);
        return dp[ind] = one+two;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(0, n, dp);
    }
};