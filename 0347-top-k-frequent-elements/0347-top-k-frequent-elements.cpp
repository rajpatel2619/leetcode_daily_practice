class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto el:nums)
            mp[el]++;
        vector<vector<int>> f;
        for(auto it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            f.push_back({it.second, it.first});}
        sort(f.begin(), f.end());
        // for(auto el:f)
        //     cout<<el[0]<<" "<<el[1]<<endl;
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(f.back()[1]);
            f.pop_back();
        }
        return res; 
    }
};