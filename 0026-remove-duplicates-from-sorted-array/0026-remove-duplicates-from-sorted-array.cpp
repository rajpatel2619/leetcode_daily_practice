class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       int num = nums[0];
       int left = 0, right = 0;
       while(right<n){
            if(nums[left]==nums[right]) right++;
            else{
                swap(nums[++left], nums[right++]);
            }
       }
       return left+1; 
    }
};