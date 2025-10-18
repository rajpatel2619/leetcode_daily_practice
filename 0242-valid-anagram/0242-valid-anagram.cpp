class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> f(26,0);
        for(auto c:s) f[c-'a']++;
        for(auto c:t) f[c-'a']--;
        for(auto e:f) cout<<e<<" ";
        for(auto e:f) if(e) return false;
        return true;
    }
};