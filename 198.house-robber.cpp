/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if(s==0) return 0;
        if(s==1) return nums[0];
        int house[s];
        house[0]=nums[0];
        house[1]=max(nums[0],nums[1]);
        for(int i=2;i<s;i++){
            house[i] = max(nums[i]+house[i-2],house[i-1]);
        }
        return house[s-1];
    }
};
// @lc code=end

