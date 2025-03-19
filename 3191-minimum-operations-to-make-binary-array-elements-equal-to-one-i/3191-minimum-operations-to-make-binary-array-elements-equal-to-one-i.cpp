class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        int i = 0;
        while(i<n && nums[i])
            i++;
        for(;i<n-2;){
            if(!nums[i] || !nums[i+1] || !nums[i+2]){
                c++;
                nums[i] = 1-nums[i];
                nums[i+1] = 1-nums[i+1];
                nums[i+2] = 1-nums[i+2];
            }
            while(i<n && nums[i])
                i++;
        }
        for(auto &e:nums)
            if(!e)
                return -1;
        return c;
    }
};