class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> left(m, 0);
        vector<int> up(n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    left[i]++;
                    up[j]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && (left[i]>1 || up[j]>1)){
                    grid[i][j] = 1;
                }else{
                    grid[i][j] = 0;
                }
            }
        }
        for(auto e:left)
            cout<<e<<" ";
        cout<<endl;
        for(auto e:up)
            cout<<e<<' ';
        cout<<endl;
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
                count+=grid[i][j];
            }
            cout<<endl;
        }
        return count;
    }
};