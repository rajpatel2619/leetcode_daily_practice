class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;
        for(auto n:nums){
            if(!s.count(n-1)){
                int len = 1;
                while(s.count(n+1)){
                    n++;
                    len++;
                }
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};