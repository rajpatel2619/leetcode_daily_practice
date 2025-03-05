class Solution {
public:
    long long coloredCells(int n) {
        long long res = 1;
        int p = 1;
        while(--n){
            res+=4*p;
            p++;
        }
        return res;
    }
};