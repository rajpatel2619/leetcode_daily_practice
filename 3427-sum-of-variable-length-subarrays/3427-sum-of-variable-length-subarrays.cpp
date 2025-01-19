class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            int s = 0;
            for(int j=max(0, i-nums[i]);j<=i;j++){
                s+=nums[j];
            }
            sum+=s;
        }   
        return sum;
    }
};