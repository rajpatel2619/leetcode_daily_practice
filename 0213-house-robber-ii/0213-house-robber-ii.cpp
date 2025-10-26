class Solution {
public:
    int rob1(vector<int>& nums, int s, int e) {

        vector<int> dp(e-s+1, 0);

        // base case
        dp[s] = nums[s];
        int p = nums[s], sp = 0;
        for(int i=s+1;i<e;i++){
            int ntake = p;
            int take = nums[i];
            if(i-2>=0)
                take += sp;
            sp = p;
            p =  max(take, ntake);
        }
        return p;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(rob1(nums, 0, n-1), rob1(nums, 1, n));
    }
};