class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pl = part.length();
        string res = "";
        for(char c:s)
        {
            res.push_back(c);
            if(res.size()>=pl && res.substr(res.size()-pl)==part)
                res.erase(res.size()-pl);
        }
        return res;
    }
};