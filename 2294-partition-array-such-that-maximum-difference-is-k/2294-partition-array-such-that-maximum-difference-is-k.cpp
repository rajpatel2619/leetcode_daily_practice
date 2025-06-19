// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int count = 0;
//         int mini = nums[0];
//         for(int i=0;i<n;i++){
//             if(nums[i]-mini <= k) continue;
//             else{
//                 count++;
//                 mini = nums[i];
//             }
//         }
//         return count+1;
//     }
// };


class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // [1, 2, 3, 5, 6], k = 2
        int mini = nums[0];
        int count = 0;
        for(int i=1;i<n;i++){
            if((nums[i]-mini)>k){
                count++;
                mini = nums[i];
            }
        }
        count++;
        return count;
    }
};