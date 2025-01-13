class Solution {
public:
    int minimumLength(string s) {
        vector<int> f(26,0);
        for(auto &ch:s)
            f[ch-'a']++;
        int c = 0;
        for(auto &n:f)
            if(n<3)
                c+=n;
            else if(n&1)
                c++;
            else c+=2;
        return c;
    }
};