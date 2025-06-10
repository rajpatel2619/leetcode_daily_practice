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
            else even = min(even, val);
        }
        return odd-even;
    }
};