class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p = 0, c = 0, r = n-1;
        while(c<=r){
            if(nums[c]==2){
                swap(nums[c], nums[r--]);
            }else if(nums[c]==0){
                swap(nums[p++], nums[c]);
            }else{
                c++;
            }
            if(c<p)
                c=p;
        }
    }
};