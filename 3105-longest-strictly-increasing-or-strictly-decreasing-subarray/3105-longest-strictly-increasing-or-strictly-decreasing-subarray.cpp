class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        // inc
        int len = 0;
        int el = 0;
        int c = 0;
        for(int i=0;i<n;i++){
            if(nums[i]>el){
                c++;
                el = nums[i];
            }
            else{
                len = max(len, c);
                c=1;
                el = nums[i];
            }
        }

        len = max(len, c);
        // dec
        el = 51;
        c = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<el){
                el = nums[i];
                c++;
            }
            else{
                len = max(len, c);
                c=1;
                el = nums[i];
            }
        }
        len = max(len, c);
        return len;
    }
};