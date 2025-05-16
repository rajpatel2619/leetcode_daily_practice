class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        queue<int> q;
        int pv = 0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            pv++;
            q.push(i);
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                vis[node] = 1;
                for(int j=0;j<n;j++){
                    if(!vis[j] and isConnected[node][j]){
                        q.push(j);
                    }
                }
            }
        }
        return pv;
    }
};