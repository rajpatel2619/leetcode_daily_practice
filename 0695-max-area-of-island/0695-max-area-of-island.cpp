class Solution {
public:
    int func(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[r][c] = true;
        int sum = 0;
        queue<pair<int, int>>q;
        q.push({r, c});
        int dir[5] = {-1, 0 , 1, 0, -1};
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            sum+=1;
            for(int i=0;i<4;i++){
                int newr = node.first+dir[i];
                int newc = node.second+dir[i+1];
                if(newr>=0 && newr<m && newc>=0 && newc<n && grid[newr][newc] && !vis[newr][newc]){
                    vis[newr][newc] = true;
                    q.push({newr, newc});
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans = max(ans, func(i,j, grid));
                }
            }
        }
        return ans;
    }
};