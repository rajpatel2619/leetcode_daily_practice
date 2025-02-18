class Solution {
public:
    bool valid(string &p, string &res, int ind, vector<bool> vis){
        if(ind==p.size())
            return true;
        for(int i=1;i<=9;i++){
            if(p[ind]=='I'){
                if(!vis[i] && i>res.back()-'0'){
                    res+=to_string(i);
                    vis[i] = 1;
                    if(valid(p, res, ind+1, vis))
                        return true;
                    res.pop_back();
                    vis[i] = 0;
                }
            }else{
                if(!vis[i] && i<res.back()-'0'){
                    res+=to_string(i);
                    vis[i] = 1;
                    if(valid(p, res, ind+1, vis))
                        return true;
                    res.pop_back();
                    vis[i] = 0;
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        string res = "";
        vector<bool> vis(10, false);
        for(int i=1;i<=9;i++){
            res+=to_string(i);
            vis[i] =1;
            if(valid(pattern, res, 0, vis))
                return res;
            vis[i] = 0;
            res.pop_back();
        }
        return res;
    }
};