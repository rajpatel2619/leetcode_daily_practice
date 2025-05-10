class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int co = 0, ct = 0;
        long long so = 0, st = 0;
        for(int el:nums1){
            so+=el;
            if(el==0)
                co++;
        }
        for(int el:nums2){
            st+=el;
            if(el==0)
                ct++;
        }
        so+=co;
        st+=ct;

        if(so>st and ct==0) return -1;
        if(st>so and co==0) return -1;
        return max(so,st);
    }
};