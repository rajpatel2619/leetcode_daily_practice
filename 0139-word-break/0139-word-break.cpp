class Solution {
public:
    bool func(int ind, string &str, unordered_set<string> &ust, vector<int> &dp){
        if(ind==str.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        for(int i=ind;i<str.size();++i){
            if(ust.count(str.substr(ind, i-ind+1)))
                if(func(i+1, str, ust, dp))
                    return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n, -1);
        return func(0, s, st, dp);
    }
};