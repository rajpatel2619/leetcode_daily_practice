class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int mn = nums[0];
        for(int i=0;i<n;i++){
            p = max(p, nums[i]-mn);
            mn = min(mn, nums[i]);
        }
        return p;
    }
};