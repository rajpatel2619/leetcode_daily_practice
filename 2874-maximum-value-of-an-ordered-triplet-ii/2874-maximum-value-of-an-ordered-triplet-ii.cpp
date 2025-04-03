class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        long long maxi = 0;
        int lm = 0;
        int diff = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi, (long long)diff*nums[i]);
            diff = max(diff, lm-nums[i]);
            lm = max(lm, nums[i]);
        }
        return maxi;
    }
};