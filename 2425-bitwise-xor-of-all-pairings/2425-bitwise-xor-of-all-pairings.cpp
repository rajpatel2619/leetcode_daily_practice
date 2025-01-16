class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = 0;
        if(n&1){
            for(auto &e:nums2)
                ans^=e;
        }

        if(m&1){
            for(auto &e:nums1)
                ans^=e;
        }

        return ans;
    }
};