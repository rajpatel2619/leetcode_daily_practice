class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto &e:nums){
            if(mp.find(e)!=mp.end()){
                return true;
            }else{
                mp[e]++;
            }
        }
        return false;
    }
};