class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        int i=0;
        int k=1;
        for(int j=1;j<n;j++){
            if(nums[i]!=nums[j]){
                swap(nums[++i], nums[j]);
                k++;
            }
        }
        for(auto e:nums)
            cout<<e<<" ";
        return k;
    }
};