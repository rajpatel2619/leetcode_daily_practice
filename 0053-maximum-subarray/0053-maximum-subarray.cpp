class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int csum = 0;
        for(int i=0;i<n;i++){
            csum = csum+nums[i];
            maxi = max(maxi, csum);
            if(csum<=0){
                csum = 0;
            }
        }
        return maxi;
    }
};