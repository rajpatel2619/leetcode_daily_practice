class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, nums[n-1]);
        for(int i=n-2;i>=0;i--)
            res[i] = res[i+1]*nums[i];
        int curr = 1;
        for(int i=0;i<n;i++){
            if(i==0){
                res[i] = curr*res[i+1];

            }else if(i==n-1){
                res[i] = curr;

            }else{
                res[i] = curr*res[i+1];

            }
            curr*=nums[i];
        }
        return res;
    }
};