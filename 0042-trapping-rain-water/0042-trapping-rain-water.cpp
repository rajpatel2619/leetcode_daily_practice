class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, nums[0]), suff(n, nums[n-1]);
        for(int i=1;i<n;i++)
            pref[i] = max(pref[i-1], nums[i]);
        for(int i=n-2;i>=0;i--)
            suff[i] = max(suff[i+1], nums[i]);
        int water = 0;
        for(int i=1;i<n-1;i++){
            water+=max(0, min(pref[i-1], suff[i+1])-nums[i]);
        }
        return water;
    }
};