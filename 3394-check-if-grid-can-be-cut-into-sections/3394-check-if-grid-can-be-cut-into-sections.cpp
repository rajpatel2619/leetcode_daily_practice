class Solution {
public:
    bool check(vector<pair<int, char>> arr){
        int o = 0;
        int l = 0;
        for(auto &e:arr){
            if(e.second=='s') o++;
            else o--;
            if(o==0) l++;
            if(l>=3) return true;
        }
        return false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rects) {
        int s = rects.size();
        vector<pair<int, char>> x;
        for(auto &e:rects){
            x.push_back({e[0], 's'});
            x.push_back({e[2], 'e'});
        }
        sort(x.begin(), x.end());
        if(check(x)) return true;
        x.clear();
        for(auto &e:rects){
            x.push_back({e[1], 's'});
            x.push_back({e[3], 'e'});
        }
        sort(x.begin(), x.end());
        return check(x);
    }
};