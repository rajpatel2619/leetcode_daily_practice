class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        unordered_set<string> ust(wl.begin(), wl.end());
        unordered_set<string> vis;
        if(ust.count(ew)==0) return 0;
        queue<pair<string, int>> q;
        q.push({bw, 1});
        vis.insert(bw);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(node.first==ew) return node.second;
            for(char ch = 'a';ch<='z';ch++){
                for(int i=0;i<node.first.size();i++){
                    string str = node.first;
                    str[i] = ch;
                    if(ust.count(str) and vis.count(str)==0){
                        q.push({str, node.second+1});
                        vis.insert(str);
                    }
                }
            }
        }
        return 0;
    }
};