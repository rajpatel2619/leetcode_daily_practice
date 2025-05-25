class Solution {
public:
    string largestPalindromic(string s) {
        int n = s.size();
        vector<int> f(10,0);
        for(auto c:s)
            f[c-'0']++;
        string left = "";
        for(int i=9;i>=0;i--){
            if (left.empty() && i == 0) continue;
            if(f[i]>1){
                int c = f[i]/2;
                left += string(c, '0' + i);
                f[i]-=c*2;
            }
        }
        int i;
        for(i=9;i>=0;i--){
            if(f[i]%2)
                break;
        }
        string res = left;
        if(i>=0){   
            res+=to_string(i);
        }
        reverse(left.begin(), left.end());
        res+=left;
        if(!res.size()) return "0";
        return res;
    }
};