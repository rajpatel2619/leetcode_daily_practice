class Solution {
public:
    long long coloredCells(int n) {
        return 1+((long long)n*4*(n-1)/2);
    }
};