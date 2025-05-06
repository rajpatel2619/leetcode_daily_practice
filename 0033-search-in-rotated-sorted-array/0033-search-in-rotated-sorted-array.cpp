class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while(left<right){
            int mid = left+ (right-left)/2;
            if(nums[mid]>nums[right])
                left = mid+1;
            else right = mid;
        }
        //left (rotated index)
        int id1 = lower_bound(nums.begin(), nums.begin()+left, target)-nums.begin();
        if(id1<n && nums[id1]==target) return id1;
        int id2 = lower_bound(nums.begin()+left, nums.end(), target)-nums.begin();
        if(id2<n && nums[id2]==target) return id2;

        return -1;
    }
};