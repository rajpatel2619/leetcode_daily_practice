class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;
        for(auto n:s){
            if(s.find(n-1)==s.end()){
                int len = 1;
                while(s.find(n+1)!=s.end()){
                    n++;
                    len++;
                }
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};