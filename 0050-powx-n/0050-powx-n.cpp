class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative  = n<0?true:false;
        double ans = 1.0;
        long long N = n;
        if(isNegative)
            N*=-1;
        while(N){
            if(N&1)
                ans*=x;
            x*=x;
            N>>=1;
        }
        if(isNegative) return 1/ans;
        return ans;
    }
};