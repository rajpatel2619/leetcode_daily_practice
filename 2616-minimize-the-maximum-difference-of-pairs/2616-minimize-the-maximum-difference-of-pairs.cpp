class Solution {
public:
    bool valid(vector<int> &nums, int mid, int p){
        int count = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] <= mid){
                count++;
                i++; // skip next to avoid overlapping (1, 1, 1, 1)
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back();
        int ans = right;
        while(left <= right){
            int mid = (left + right) / 2;
            if(valid(nums, mid, p)){
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
