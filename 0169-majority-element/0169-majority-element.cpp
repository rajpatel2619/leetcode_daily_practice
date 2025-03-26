class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int c=1;
        for(int i=1;i<n;i++){
            if(el==nums[i]){
                c++;
            continue;
            }
            
            c--;
            if(c==0){
                el=nums[i];
                c=1;
            }
        }
        return el;
    }
};