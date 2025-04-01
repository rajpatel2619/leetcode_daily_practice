class Solution {
public:
    long long func(int ind, vector<vector<int>>& qu,vector<long long>&dp){
        if(ind>=qu.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];

        long long take = qu[ind][0] + func(ind+qu[ind][1]+1, qu,dp);
        long long ntake = 0 + func(ind+1,qu,dp);
        return dp[ind] = max(take, ntake);
       
    }
    long long mostPoints(vector<vector<int>>& qu) {
        int n = qu.size();
        vector<long long> dp(n,-1);
        return func(0,qu,dp);
    }
};