class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        long long sumt = accumulate(nums.begin(), nums.end(), 0ll);
        long long sumc = 0;
        for(int i=0;i<n;i++){
            sumt-=nums[i];
            if(sumc==sumt) return i;
            sumc+=nums[i];
        }
        return -1;
    }
};