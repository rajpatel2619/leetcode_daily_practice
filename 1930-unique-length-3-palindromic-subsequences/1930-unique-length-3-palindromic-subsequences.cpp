class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, pair<int, int>> mp;
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(mp.find(ch)!=mp.end()){
                mp[ch].second = i;
            }else{
                mp[ch].first = mp[ch].second = i;
            }
        }
        // 
        int count = 0;
        for(auto [ch, p]:mp){
            if(p.first==p.second) continue;
            unordered_set<char> st(s.begin()+p.first+1, s.begin()+p.second);
            count+=st.size();
        }
        return count;
    }
};