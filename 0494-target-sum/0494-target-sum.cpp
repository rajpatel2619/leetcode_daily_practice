class Solution {
public:
    int count = 0;
    void fuck(int ind, vector<int> &arr, int sum, int tar){
        if(ind == arr.size()){
            if(sum==tar)
                count++;
            return;
        }
        // int plus = 
        fuck(ind+1, arr, sum+arr[ind], tar);
        // int minus = 
        fuck(ind+1, arr, sum-arr[ind], tar);
        // return max(plus, minus);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         fuck(0, nums, 0, target);
         return count;
    }
};