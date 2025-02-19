class Solution {
public:
    bool func(int ind, int n, int &k, string &str, char c){
        if(ind==n){
            if(k==1)
                return true;
            k--;
            return false;
        };
        vector<char> arr = {'a','b','c'};
        for(auto ch:arr){
            if(ch!=c){
                str.push_back(ch);
                if(func(ind+1, n, k, str, ch))
                    return true;
                str.pop_back();
            }
        }
        return false;
    }
    string getHappyString(int n, int k) {
        string str = "";
        if(func(0, n, k, str, 'd'))
            return str;
        return "";
    }
};