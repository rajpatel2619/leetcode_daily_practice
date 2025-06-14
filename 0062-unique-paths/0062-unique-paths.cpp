class Solution {
public:
    int paths(int i, int j, vector<vector<int>> &dp){
        if(i==0 and j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int top = 0, left = 0;
        if(i-1 >=0)
            top=paths(i-1, j, dp);
        if(j-1 >=0)
            left = paths(i, j-1, dp);
        return dp[i][j] = top+left; 
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m-1, n-1, dp);
    }
};