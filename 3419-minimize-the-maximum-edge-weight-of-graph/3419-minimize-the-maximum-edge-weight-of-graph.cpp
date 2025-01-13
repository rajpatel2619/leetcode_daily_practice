class Solution {
public:
    bool func(vector<vector<pair<int, int>>>&adj, int val, int n){
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] =true;
        int cnt = 1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto &[f,s]:adj[node]){
                if(s<=val && !vis[f]){
                    vis[f] =true;
                    q.push(f);
                    cnt++;
                }
            }
        }
        return cnt==n;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &e:edges)
            adj[e[1]].push_back({e[0], e[2]});
        int l = 0, r = 1e6, ans = -1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(func(adj, m, n)){
                ans = m;
                r = m-1;
            }else
                l = m+1;
        }
        return ans;
    }
};