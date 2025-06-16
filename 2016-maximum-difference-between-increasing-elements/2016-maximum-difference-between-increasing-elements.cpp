class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = -1, maxi = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]==maxi) continue;
            res = max(maxi-nums[i], res);
            maxi = max(maxi, nums[i]);
        }
        return res;
    }
};