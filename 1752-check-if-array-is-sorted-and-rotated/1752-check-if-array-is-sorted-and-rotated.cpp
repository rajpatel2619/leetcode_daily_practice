class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int i=1;
        while(i<n && nums[i]>=nums[i-1])
            i++;
        if(i==n) return true;
        reverse(nums.begin(), nums.begin()+i);
        reverse(nums.begin()+i, nums.end());
        reverse(nums.begin(), nums.end());
        // for(auto e:nums)
        //     cout<<e<<" ";
        for(int i=0;i<n-1;i++)
            if(nums[i]>nums[i+1])
                return false;
        return true;
    }
};