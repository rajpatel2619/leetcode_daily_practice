class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int max_till_now = -1, last_seen_max = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]==last_seen_max) continue;
            max_till_now = max(last_seen_max-nums[i], max_till_now);
            last_seen_max = max(last_seen_max, nums[i]);
        }
        return max_till_now;
    }
};