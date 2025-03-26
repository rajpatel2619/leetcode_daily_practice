class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (i < 1|| nums[i - 1] != nums[j]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
