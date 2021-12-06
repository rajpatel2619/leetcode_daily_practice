/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int length = s.length();
        vector<int> arr(26,0);
        for(int i=0;i<length;i++) arr[s[i]-'a']++;
        for(int i=0;i<length;i++)
            if(arr[s[i]-'a']==1) return i;
        // else
        return -1; 
    }
};
// @lc code=end

