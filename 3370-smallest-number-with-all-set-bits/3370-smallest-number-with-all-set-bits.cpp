class Solution {
public:
    int smallestNumber(int n) {
        int i = 2;
        while(i<=n)i<<=1;
        return i-1;
    }
};