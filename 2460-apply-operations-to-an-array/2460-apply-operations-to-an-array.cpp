class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int f = 0;
        while(f<n && nums[f]!=0)
            f++;
        for(int p=f+1;p<n;p++){
            if(nums[p]!=0){
                swap(nums[p], nums[f]);
                f++;
            }
        }
        return nums;
    }
};