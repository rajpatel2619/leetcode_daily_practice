class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0, lmax=nums[0], r = n-1, rmax = nums[n-1];
        int maxi = 0;
        while(l<=r){
            lmax = max(lmax, nums[l]);
            rmax = max(rmax, nums[r]);
            if(lmax<=rmax){
                int mini = min(lmax, rmax);
                maxi = max(maxi, mini*(r-l));
                l++;
            }else{
                int mini = min(lmax, rmax);
                maxi = max(maxi, mini*(r-l));
                r--;
            }
        }
        return maxi;
    }
};