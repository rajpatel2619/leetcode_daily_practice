class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int tp = 1;
        int zi = -1;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(zi>=0){
                    return arr;
                }else
                    zi=i;
            }else{
                tp*=nums[i];
            }
        }
        
        if(zi>=0){
            arr[zi] = tp;
            return arr;
        }

        for(int i=0;i<n;i++){
            arr[i] = tp/nums[i];
        }
        return arr;
    }
};