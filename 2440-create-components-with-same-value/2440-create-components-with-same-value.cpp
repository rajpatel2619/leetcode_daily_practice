class Solution {
public:
    int count = 0;
    int dfs(int node, vector<vector<int>>&gph, vector<int> &vals, int k, int par=-1){
        long long sum = vals[node];
        for(auto &nd:gph[node]){
            if(nd!=par) 
                sum+= dfs(nd, gph, vals, k, node);
            if(sum>k) return 1e7;
        }
        if(sum==k) return 0;
        return sum;
    }
    
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> gph(n);
        for(auto &ed:edges){
            gph[ed[0]].push_back(ed[1]);
            gph[ed[1]].push_back(ed[0]);
        }
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i=n;i>1;i--){
            if(sum%i) continue;
            if(dfs(0, gph, nums, sum/i)==0) return i-1;
        }
        return 0;
    }
};