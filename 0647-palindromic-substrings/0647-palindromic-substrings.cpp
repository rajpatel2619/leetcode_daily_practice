class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int mlen = 0;
        int count=0;
        for(int i=0;i<n;i++){
            // odd..
            int l=i, r=i;
            while(l>=0 and r<n and s[l]==s[r]){
                l--;
                r++;
                count++;
            }
            //even
            l=i-1, r = i;
            while(l>=0 and r<n and s[l]==s[r]){
                count++;
                l--;
                r++;
            }
        }
        return count;
    }
};