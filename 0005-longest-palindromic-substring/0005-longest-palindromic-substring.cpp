class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int mlen = 0;
        string res;
        for(int i=0;i<n;i++){
            // odd..
            int l=i, r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>mlen){
                    mlen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
            //even
            l=i, r = i+1;
            while(l>=0 and r<n and s[l]==s[r]){
                if(r-l+1>mlen){
                    mlen = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};