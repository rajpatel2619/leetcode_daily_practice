class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int csum = 0;
        int count = 0;
        for(auto e:nums){
            if(e==0){
                if(csum==sum) count+=2;
                else if(abs(csum-sum)==1) count+=1;
            }else{
                csum+=e;
                sum-=e;
            }
        }
        return count;
    }
};