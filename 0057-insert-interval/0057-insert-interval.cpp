class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& its) {
        vector<vector<int>> res;
        sort(its.begin(), its.end());
        int n = its.size();
        res.push_back(its[0]);
        for(int i=1;i<n;++i){
            auto node = its[i];
            if(node[0]<=res.back()[1]){
                res.back()[1] = max(res.back()[1], node[1]);
            }else{
                res.push_back(node);
            }
        }
        return res;
    }
    vector<vector<int>> insert(vector<vector<int>>& its, vector<int>& nit) {
        its.emplace_back(nit);
        sort(its.begin(), its.end());
        return merge(its);
    }
};