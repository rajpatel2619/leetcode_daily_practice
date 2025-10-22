class Solution {
public:
    int count(string &str, int k, char ch){
        int l=0, r=0, n = str.size(), cnt = 0, maxi = 0;
        while(r<n){
            char c = str[r++];
            if(c!=ch){
                cnt++;
                if(cnt>k){
                    while(l<r and cnt>k){
                        if(str[l++]!=ch)cnt--;
                    }
                }
            }
            maxi = max(maxi, r-l);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int maxi = 0;
        for(char ch='A';ch<='Z';ch++){
            maxi = max(maxi, count(s, k, ch));
        }
        return maxi;
    }
};