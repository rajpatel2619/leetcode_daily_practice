class Solution {
public:
    void func(int n, int o, int c, string &path, vector<string> &res){
        if(path.size()==2*n){
            res.push_back(path);
            return;
        }
        string s1 = path+"(";
        string s2 = path+")";
        if(o<n) func(n, o+1, c, s1, res);
        if(c<o) func(n, o, c+1, s2, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "(";
        func(n, 1, 0, path, res);
        return res;
    }
};