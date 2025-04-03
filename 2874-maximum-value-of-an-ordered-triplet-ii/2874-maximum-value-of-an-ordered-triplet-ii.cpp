class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        arr[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            arr[i] = max(arr[i+1], nums[i]);
        
        long long maxi = 0;
        int lm = nums[0];
        for(int i=1;i<n-1;i++){
            maxi = max(maxi, (long long)arr[i+1]*(lm-nums[i]));
            lm = max(lm, nums[i]);
        }
        return maxi;
    }
};