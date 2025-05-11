class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto el:nums)
            mp[el]++;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
        for(auto [n, f]:mp){
            pq.push({f, n});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            auto n = pq.top();
            pq.pop();
            res.push_back(n.second);
        }
        return res;
    }
};