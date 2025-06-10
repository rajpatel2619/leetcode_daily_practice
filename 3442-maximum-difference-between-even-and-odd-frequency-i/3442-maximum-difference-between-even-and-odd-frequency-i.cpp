class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> f;
        for(auto ch:s)
            f[ch-'a']++;
        int odd = INT_MIN, even = INT_MAX;
        for(auto [key, val]:f){
            if(val&1)
                odd = max(odd, val);
            else if(val!=0) even = min(even, val);
        }
        if(even==INT_MAX) return odd;
        return odd-even;
    }
};