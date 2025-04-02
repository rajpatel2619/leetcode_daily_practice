class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxi = 0;
        vector<int> mx(n), mn(n);
        mx[0] = nums[0];
        for(int i=1;i<n;i++){
            mx[i] = max(mx[i-1], nums[i]);
        }
        mn[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mn[i] = max(mn[i+1], nums[i]);
        }
        for(int i=1;i<n-1;i++){
                maxi = max(maxi, (long long)mn[i+1]*(mx[i-1]-nums[i]));
        }
        return maxi;
    }
};