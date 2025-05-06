class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1) arr[i]=nums[i];
            else arr[i] = nums[i]*arr[i+1];
        }
        int cp = 1;
        for(int i=0;i<n;i++){
            if(i==n-1){
                arr[i] = cp;
            }else{
                arr[i] = cp*arr[i+1];
                cp*=nums[i];
            }
        }
        return arr;
    }
};