class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = nums[0];
        int cs = nums[0];
        int el = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                maxi = max(maxi, cs);
                cs = nums[i];
                el = nums[i];
            }else{
                cs+=nums[i];
                el = nums[i];
            }
        }
        return max(maxi, cs);
    }
};