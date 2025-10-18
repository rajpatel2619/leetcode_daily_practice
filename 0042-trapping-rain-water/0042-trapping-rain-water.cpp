class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int l = 0, lmax = nums[0], r = n-1, rmax = nums[n-1];
        int water = 0;
        while(l<=r){
            lmax = max(lmax, nums[l]);
            rmax = max(rmax, nums[r]);
            if(lmax<=rmax){
                water+=max(0, min(lmax, rmax)-nums[l]);
                l++;
            }else{
                water+=max(0, min(lmax, rmax)-nums[r]);
                r--;
            }
        }
        return water;
    }
};