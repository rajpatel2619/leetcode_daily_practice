class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n = nums.size();
        long long mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i<n-1;i++){
            long long temp = nums[i+1]+nums[i];
            mini = min(mini, temp);
            maxi = max(maxi, temp);
        }
        return maxi-mini;
    }
};