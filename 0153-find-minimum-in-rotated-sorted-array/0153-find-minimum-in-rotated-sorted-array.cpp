class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0, r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(m==0) return min(nums[n-1],nums[0]);
            if(m==n-1) return min(nums[n-1], nums[0]);
            if(nums[m]<nums[m-1] and nums[m]<nums[m+1]) return nums[m];
            else if(nums[m]<= nums[n-1]) r = m;
            else l = m+1;
        }
        return -1;
    }
};