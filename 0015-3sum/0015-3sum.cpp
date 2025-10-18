class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            int j = i+1, k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k and nums[j]==nums[j-1]) j++;
                }else if(sum<0) j++;
                else k--;
            }
            while(i+1<n and nums[i]==nums[i+1])i++;
        }
        return res;
    }
};