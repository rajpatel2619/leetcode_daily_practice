class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> mat(m, vector<int>(n,0));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    vis[i][j] = true;
                    q.push({i,j});
                    mat[i][j] = 0;
                }
            }
        }
        int level = 0;
        int dir[5] = {-1,0,1,0,-1};
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto node= q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int nr = node.first+dir[j];
                    int nc = node.second+dir[j+1];
                    if(nr<m && nr>=0 && nc<n && nc>=0 && !grid[nr][nc] && !vis[nr][nc]){
                        mat[nr][nc] = level+1;
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            level++;
        }
        return mat;
    }
};