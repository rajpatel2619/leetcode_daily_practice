class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int,int>> arr;
        
        for(int i=0;i<nums.size();i++){
            arr.push_back({nums[i], i});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>>pq(arr.begin(), arr.end());

        while(k--){
            auto [el, ind] = pq.top();
            pq.pop();
            pq.push({el*multiplier, ind});
        }
        while(!pq.empty()){
            auto [el, ind] = pq.top();
            nums[ind] = el;
            pq.pop();
        }
        return nums;
    }
};