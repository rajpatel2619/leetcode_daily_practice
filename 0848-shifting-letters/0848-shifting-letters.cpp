class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for(int i=n-2;i>=0;i--)
            shifts[i] = (shifts[i]+shifts[i+1])%26;
        for(int i=0;i<n;i++){
            char ch = s[i];
            ch = (((ch-'a')+shifts[i])%97)+'a';
            // cout<<ch<<" ";
            s[i] = ch;
        }
        return s;
    }
};