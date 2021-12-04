/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       set<int> res;
       for(int i=0;i<nums.size();i++){
           res.insert(nums[i]);
       }
       int i=0;
        for(auto e:res ){
            nums[i] =e;
            i++;
        }
       return res.size();


    }
};
// @lc code=end

