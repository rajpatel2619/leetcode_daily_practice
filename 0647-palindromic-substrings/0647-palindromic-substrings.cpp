class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s, i, j))
                    count++;
            }
        }
        return count;
    }
};
