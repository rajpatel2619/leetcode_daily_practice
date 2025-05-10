class Solution {
public:
    int func(int ind1, int ind2, string &t1, string &t2, vector<vector<int>>&dp){
        if(ind1 < 0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(t1[ind1] == t2[ind2])
            return dp[ind1][ind2] = 1+func(ind1-1, ind2-1, t1, t2, dp);
        return dp[ind1][ind2] = max(func(ind1-1, ind2, t1, t2, dp), func(ind1, ind2-1, t1, t2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return func(n1-1, n2-1, text1, text2, dp);
    }
};