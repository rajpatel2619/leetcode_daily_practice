class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict;
        for(string &e:wordDict)
            dict.insert(e);
        
        int dp[n+1];
        memset(dp,0,sizeof dp);
        
        dp[n]=1;
        
        for(int i=n-1;i>=0;i--){
            string word;
            for(int j=i;j<n;j++){
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end()){
                    if(dp[j+1])
                        dp[i]=1;
                }
            }
        }
        return dp[0];
    }
};