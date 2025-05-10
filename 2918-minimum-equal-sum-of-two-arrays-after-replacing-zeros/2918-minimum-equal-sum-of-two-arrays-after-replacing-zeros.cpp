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
        if(co==0 && ct==0){
            if(so==st) return st;
            else return -1;
        }
        else if(co==0){
            if(so>=st+ct) return so;
        }else if(ct==0){
            if(st>=so+co) return st;
        }else{
            return max(so+co,st+ct);
        }
        return -1;
    }
};