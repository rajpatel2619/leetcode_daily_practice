class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26,0);
        for(auto ch:s)
            f[ch-'a']++;
        int odd = INT_MIN, even = INT_MAX;
        for(auto fr:f){
            if(fr&1)
                odd = max(odd, fr);
            else if(fr!=0) even = min(even, fr);
        }
        if(even==INT_MAX) return odd;
        return odd-even;
    }
};