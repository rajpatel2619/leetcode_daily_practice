class Solution {
public:
    int ans = 0;
    void func(int ind, vector<int>& nums, int res){
        ans+=res;
        for(int i=ind;i<nums.size();i++){
            res^=nums[i];
            func(i+1, nums, res);
            res^=nums[i];
        }
    }
    int subsetXORSum(vector<int>& nums) {
        func(0, nums, 0);
        return ans;
    }
};