class Solution {
public:
    static bool compare(pair<int, int> &a, pair<int, int> &b){
        return (a.first>b.first);
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto e:nums) mp[e]++;

        vector<pair<int, int>> arr;
        for(auto it:mp){
            arr.push_back({it.second, it.first});
        }
        sort(arr.begin(), arr.end(), compare);
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(arr[i].second);
        return res;
    }
};