/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
     unordered_map<int,int> memo;
    int climbStairs(int n) {
        if(n<=2) return n;
        if(memo.find(n)!=memo.end()) return memo[n];
        memo[n] = climbStairs(n-1) + climbStairs(n-2);
        return memo[n];
    }
};
// @lc code=end

