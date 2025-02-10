class Solution {
public:
    string clearDigits(string s) {
        string r = "";
        for(char &c:s)
            if(isdigit(c))
                r.pop_back();
            else r+=c;
        return r;
    }
};