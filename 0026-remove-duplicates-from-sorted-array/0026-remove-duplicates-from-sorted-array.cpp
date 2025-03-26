class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        while(r<n && nums[r]==nums[l]) r++;
        while(l<n && r<n){
            swap(nums[++l], nums[r++]);
            while(r<n && nums[r]==nums[l]) r++;
        }
        return l+1;
    }
};