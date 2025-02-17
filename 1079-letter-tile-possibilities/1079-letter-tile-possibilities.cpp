class Solution {
public:
    int func(vector<int> &freq){
        int ways = 0;
        for(int i=0;i<26;i++){
            if(freq[i]){
                freq[i]--;
                ways+= 1+func(freq);
                freq[i]++;
            }
        }
        return ways;
    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(auto &ch:tiles)
            freq[ch-'A']++;
        return func(freq);
    }
};