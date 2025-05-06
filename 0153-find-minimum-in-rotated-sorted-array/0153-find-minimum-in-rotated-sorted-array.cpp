class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                ind = i;
                break;
            }
        }
        if(ind==-1) return nums[0];
        return min(nums[0], nums[ind]);
    }
};