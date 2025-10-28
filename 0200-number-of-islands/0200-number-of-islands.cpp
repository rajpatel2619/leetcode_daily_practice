class Solution {
public:
    int dfs(int r, int c, vector<vector<char>>& grid){
        if(grid[r][c]=='0') return 0;
        grid[r][c] = '0';

        int dir[5] = {-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = r+dir[i];
            int nc = c+dir[i+1];
            if(nr>=0 and nc>=0 and nr<grid.size() and nc<grid[0].size())
                dfs(r+dir[i], c+dir[i+1], grid);
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};