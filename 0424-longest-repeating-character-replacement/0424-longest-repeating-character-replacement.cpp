class Solution {
public:
    int func(char ch, string &str, int k){
        int l = 0, r = 0, n = str.size(), count = 0, maxi = 1;
        while(r<n){
            if(str[r]==ch) r++;
            else count++, r++;

            while(l<r and count>k)
                if(str[l++]!=ch) count--;
                
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int maxi = 0;
        for(char ch = 'A';ch<='Z';ch++)
            maxi = max(maxi, func(ch, s, k));
        return maxi;
    }
};