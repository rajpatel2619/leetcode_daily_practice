class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> ans;
        int n = groups.size();
        int prev = 0;
        ans.push_back(prev);
        for(int i=1;i<n;i++){
            if(groups[i]!=groups[prev]){
                ans.push_back(i);
                prev = i;
            }
        }
        vector<string>res;
        for(auto i:ans)
            res.push_back(words[i]);
        return res;
    }
};