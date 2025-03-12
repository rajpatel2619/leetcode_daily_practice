class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int p = 0, n = 0;
        for(auto &e:nums){
            if(e==0) continue;
            if(e<0)
                n++;
            else p++;
        }
        return max(p,n);
    }
};