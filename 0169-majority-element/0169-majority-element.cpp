class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int vperson = nums[0];
        int c = 1;
        for(int i=1;i<n;i++){
            if(nums[i]!=vperson)
                c--;
            else c++;
            if(c==0){
                vperson = nums[i];
                c=1;
            }
        }
        return vperson;
    }
};