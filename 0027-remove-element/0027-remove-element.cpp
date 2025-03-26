class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(r>=0 && nums[r]==val) r--;
        while(l<r){
            if(nums[l]==val){
                swap(nums[l], nums[r]);
                r--;
                while(r>=0 && nums[r]==val) r--;
            }
            l++;
        }
        int k = 0;
        while(k<n && nums[k]!=val) k++;
        return k;
    }
};