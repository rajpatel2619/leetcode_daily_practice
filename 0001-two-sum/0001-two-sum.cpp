class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int el = nums[i];
            int comp = target - el;
            if(ump.count(comp)) return{i, ump[comp]};
            ump[el] = i;
        }
        return {-1,-1};
    }
};