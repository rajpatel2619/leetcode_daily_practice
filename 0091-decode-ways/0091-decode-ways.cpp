class Solution {
public:
    int func(int ind, string &str, vector<int> &dp){
        if(ind == str.size()) return 1;
        if(ind>str.size()) return 0;
        if(str[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int count =0;
        count+=func(ind+1, str,dp);
        if(ind+2<=str.size() && str.substr(ind, ind+2)<"27")
            count+=func(ind+2, str, dp);
        return dp[ind] =count;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return func(0, s, dp);
    }
};