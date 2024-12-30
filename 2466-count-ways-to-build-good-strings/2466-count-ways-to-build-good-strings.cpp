class Solution {
public:
    int mod = 1e9+7;
    int func(int l, int h, int z, int o, int len, vector<int>&dp){
        if(len>h) return 0;
        if(dp[len]!=-1) return dp[len];
        int zlen = len+z;
        int olen = len+o;
        int zcnt = (zlen>=l && zlen<=h)?1:0;
        int ocnt = (olen>=l && olen<=h)?1:0;
        return dp[len]=(zcnt+func(l,h,z,o,zlen, dp) +ocnt +func(l,h,z,o,olen,dp))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int maxi = high + max(zero, one);
        vector<int> dp(maxi,-1);
        return func(low, high, zero, one, 0, dp);
    }
};