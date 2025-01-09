class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt =0 ;
        for(auto &w:words){
            if(s.size()<w.size()) continue;
            if(s.substr(0, w.size())==w)
                cnt++;
        }
        return cnt;
    }
};