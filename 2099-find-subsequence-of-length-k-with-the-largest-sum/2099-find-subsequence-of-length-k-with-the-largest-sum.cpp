class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr(nums.begin(), nums.end());
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        for(int j=n-1;j>=n-k;j--){
            mp[arr[j]]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(mp.count(nums[i])){
                res.push_back(nums[i]);
                mp[nums[i]]--;
            }
            if(mp[nums[i]]==0) mp.erase(nums[i]);
        }
        return res;
    }
};