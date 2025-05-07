class Solution {
public:
    int bitsCount(int i){
        int c = 0;
        while(i){
            if(i&1) c++;
            i>>=1;
        }
        return c;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++)
            ans[i] = bitsCount(i);
        return ans;
    }
};