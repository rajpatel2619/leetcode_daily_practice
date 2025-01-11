class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> f(26,0);
        int n = s.size();
        if(n<k) return false;
        for(int i=0;i<n;i++)
            f[s[i]-'a']++;
        int cnt = 0;
        for(auto &el:f)
            if(el&1)
                cnt++;
        return cnt<=k;
    }
};