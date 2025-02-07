class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> st;
        unordered_map<int, int> mp;
        vector<int> res;
        int c = 0;
        for(auto q:queries){
            if(mp.find(q[0])!=mp.end()){
                int el = mp[q[0]];
                st[el]--;
                if(st[el]<=0)
                    st.erase(el);
                mp[q[0]] = q[1];
                st[q[1]]++;
            }else{
                mp[q[0]] = q[1];
                st[q[1]]++;
            }
            res.push_back(min(mp.size(), st.size()));
        }
        return res;
    }
};