class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0], csum = 0;
        for(auto &e:nums){
            csum+=e;
            maxi = max(maxi, csum);
            if(csum<0) csum = 0;
        }
        return maxi;
    }
};