class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        for(auto c:s)
            if(c=='1')
                ones++;
            else zeros++;
        int maxi = max(ones-1, zeros-1);
        int zr = 0;
        for(int i=0;i<s.size()-1;i++){
            char ch = s[i];
            if(ch=='0'){
                zr++;
                maxi = max(maxi, ones+zr);
            }else{
                ones--;
            }
        }
        return maxi;
    }
};