class Solution {
public:
    int maxDifference(string s) {
        // frequency map [char -> freq]
        unordered_map<int, int> f;
        for(auto ch:s)
            f[ch-'a']++;
        
        // greedy way
        // diff = max_odd_freq - min_even_freq
        // picking maximum odd freq && minimum even freq
        int odd = INT_MIN, even = INT_MAX;
        for(auto [key, val]:f){
            if(val&1)
                odd = max(odd, val);
            else even = min(even, val);
        }

        return odd-even;
    }
};