class Solution {
public:
    bool func(int n, int p){
        if(n==0) return true;
        long long num = pow(3,p); 
        if(num>n) return false;
        bool t=false;
        if(num<=n){
            t = func(n-num, p+1);
        }
        if(t)
            return true;
        return func(n, p+1);
    }
    bool checkPowersOfThree(int n) {
        return func(n, 0);
    }
};