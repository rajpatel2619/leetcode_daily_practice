class Solution {
public:
    bool isPal(string &str){
        return str[0]==str[2];
    }
    int func(int ind, string &s, string &curr, unordered_set<string> &st){
        if(curr.size()==3){
            if(isPal(curr)){
                st.insert(curr);
                return 1;
            }
            else return 0;
        }
        if(ind>=s.size())
            return 0;
        string temp = curr+s[ind];
        return func(ind+1, s, temp, st) + func(ind+1, s, curr, st);
    }
    int countPalindromicSubsequence(string s) {
        unordered_set<string> st;
        string str = "";
        func(0, s,str, st);
        return st.size();
    }
};