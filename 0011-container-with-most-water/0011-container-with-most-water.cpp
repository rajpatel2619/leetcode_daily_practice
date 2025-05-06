class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int maxi = INT_MIN;
        while(left<right){
            maxi = max(maxi, min(nums[left], nums[right])*(right-left));
            if(nums[left]<=nums[right]){
                left++;
            }else
                right--;
        }
        return maxi;
    }
};