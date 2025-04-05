class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total_subsets = 1<<n;
        int res = 0;
        for(int mask=0;mask<total_subsets;mask++){
            int xrr = 0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    xrr^=nums[i];
                }
            }
            res+=xrr;
        }
        return res;
    }
};