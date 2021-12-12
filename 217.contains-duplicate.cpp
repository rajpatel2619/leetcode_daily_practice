/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> ctnr;
        for(auto &i:nums) ctnr.insert(i);
        
        if(nums.size()==ctnr.size())
            return false;
        
        return true; 
    }
};
// @lc code=end

