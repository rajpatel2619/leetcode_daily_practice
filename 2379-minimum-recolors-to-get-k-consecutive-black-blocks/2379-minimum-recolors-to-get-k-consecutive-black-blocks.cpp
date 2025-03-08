class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i=0;
        unordered_map<char, int> mp;
        mp['B'] = 0;
        mp['W'] = 0;
        while(i<k){
            mp[blocks[i]]++;
            i++;
        }
        int mini = mp['W'];
        for(i;i<n;i++){
            mp[blocks[i-k]]--;
            mp[blocks[i]]++;
            mini = min(mini, mp['W']);
        }
        return mini;
    }
};