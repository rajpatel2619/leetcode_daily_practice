class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
       priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> mnpq;
       for(int i=0;i<nums.size();i++){
            if(mnpq.size()<k) mnpq.push({nums[i], i});
            else if(mnpq.top().first<nums[i]){
                mnpq.pop();
                mnpq.push({nums[i], i});
            }
       }
       vector<pair<int, int>> arr;
       while(!mnpq.empty()){
            arr.push_back({mnpq.top().second, mnpq.top().first});
            mnpq.pop();
       }
       sort(arr.begin(), arr.end());
       vector<int> res;
       for(auto el:arr)
        res.push_back(el.second);
        return res;

    }
};