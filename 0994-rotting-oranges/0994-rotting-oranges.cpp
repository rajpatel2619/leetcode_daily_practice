class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int c = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j] = true;
                    q.push({i,j});
                    c++;
                }
            }
        }
        
        int level = 0;
        int dir[5] = {-1,0,1,0,-1};
        while(!q.empty()){
            int s = q.size();
            level++;
            for(int i=0;i<s;i++){
                auto node= q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = node.first+dir[j];
                    int nc = node.second+dir[j+1];
                    if(nr<m && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==1 && !vis[nr][nc]){
                        vis[nr][nc] = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(c==0) return 0;
        return level-1;
    }
};