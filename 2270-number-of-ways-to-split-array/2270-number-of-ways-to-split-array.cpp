class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sumt = accumulate(nums.begin(), nums.end(), 0ll);
        long long sumc = 0;
        int count = 0;
        for(int i=0;i<n-1;i++){
            sumc+=nums[i];
            sumt-=nums[i];
            if(sumc>=sumt)
                count++;
        }
        return count;
    }
};