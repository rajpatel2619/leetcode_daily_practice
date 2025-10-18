class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ust(nums.begin(), nums.end());
        int maxi = 0;
        for(int e:ust){
            if(!ust.count(e-1)){
                int len = 1;
                while(ust.count(++e)) len++;
                maxi= max(maxi, len);
            }
        }
        return maxi;
    }
};