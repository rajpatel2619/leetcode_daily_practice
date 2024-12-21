class Solution {
    int count = 0;
public:
    int dfs(int node, int n, vector<vector<int>>&gph, vector<int> &vals, int k, int par=-1){
        long long sum = vals[node];
        for(auto &nd:gph[node]){
            if(nd!=par) 
                sum+= dfs(nd, n, gph, vals, k, node);
        }
        if(sum%k==0)
            count++;
        return sum%k;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& e, vector<int>& v, int k) {
        vector<vector<int>> gph(n);
        for(auto &ed:e){
            gph[ed[0]].push_back(ed[1]);
            gph[ed[1]].push_back(ed[0]);
        }
    
        dfs(0, n, gph, v,k);
        return count;
    }
};