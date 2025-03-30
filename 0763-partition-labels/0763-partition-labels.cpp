class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        for(auto &c:s)
            mp[c]++;
        
        vector<int> res;
        int i = 0;
        int n = s.size();
        while(i<n){
            unordered_map<char, int> cur;
            cur[s[i]] = mp[s[i]];
            int len = 0;
            while(i<n && cur.size()>0){
                len++;
                if(cur.find(s[i])==cur.end()){
                    cur[s[i]] = mp[s[i]]-1;
                }else{
                    cur[s[i]]--;
                }
                if(cur[s[i]]==0) cur.erase(s[i]);
                i++;
            }
            res.push_back(len);
        }
        return res;
    }
};