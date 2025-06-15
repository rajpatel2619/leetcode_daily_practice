class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto e:nums)
            mp[e]++;
        vector<int> res;
        for(auto [k, v]:mp)
            if(v>n/3) res.push_back(k);
        return res;
    }
};