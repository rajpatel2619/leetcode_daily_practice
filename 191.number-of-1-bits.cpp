/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        while(n>0){
            n=n&(n-1);
            ans++;
        }
        return ans; 
    }
};
// @lc code=end

