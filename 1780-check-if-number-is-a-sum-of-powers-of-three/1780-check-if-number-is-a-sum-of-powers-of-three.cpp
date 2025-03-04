class Solution {
public:
    bool func(int n, int p){
        if(n==0) return true;
        if(pow(3,p)>n) return false;
        bool t=false;
        if(pow(3, p)<=n){
            t = func(n-pow(3,p), p+1);
        }
        if(t)
            return true;
        return func(n, p+1);
    }
    bool checkPowersOfThree(int n) {
        return func(n, 0);
    }
};