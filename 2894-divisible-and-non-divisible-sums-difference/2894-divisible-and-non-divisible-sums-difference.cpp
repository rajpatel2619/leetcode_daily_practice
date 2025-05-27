class Solution {
public:
    int differenceOfSums(int n, int m) {
        int s_one = 0, s_two = 0;
        for(int i=1;i<=n;i++){
            if(i%m) s_one+=i;
            else s_two+=i;
        }
        return s_one-s_two;
    }
};