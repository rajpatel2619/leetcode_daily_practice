class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r=n-1, m=0;
        while(m<r){
            if(nums[m]==2){
                swap(nums[m], nums[r]);
                r--;
            }else{
                m++;
            }
        }
        if(nums[r]==2)
            r--;
        m=0;
        while(m<r){
            if(nums[m]==1){
                swap(nums[m], nums[r]);
                r--;
            }else{
                m++;
            }
        }
        
    }
};