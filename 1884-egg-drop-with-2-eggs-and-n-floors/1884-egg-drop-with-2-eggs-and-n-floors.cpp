class Solution {
public:
    int solve(int e, int f, vector<vector<int>>&dp){
        if(e==1 || f==0 || f==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mini = 1e9;
        for(int i=1;i<=f;i++){
            mini = min(mini, 1+max(solve(e-1, i-1, dp), solve(e, f-i, dp)));
        }
        return dp[e][f] = mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(2+1, vector<int>(n+1,-1));
        return solve(2, n, dp);
    }
};