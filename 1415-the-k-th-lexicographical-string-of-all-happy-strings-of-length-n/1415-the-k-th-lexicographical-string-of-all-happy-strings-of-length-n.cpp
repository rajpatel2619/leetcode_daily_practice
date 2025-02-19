class Solution {
public:
    void func(int ind, int n, string &str, vector<string> &res, char c){
        if(ind==n){
            res.push_back(str);
            return;
        };
        vector<char> arr = {'a','b','c'};
        for(auto ch:arr){
            if(ch!=c){
                str.push_back(ch);
                func(ind+1, n, str, res, ch);
                str.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<string> res;
        string str = "";
        func(0, n,str, res, 'd');
        if(res.size()<k)
            return "";
        return res[k-1];
    }
};