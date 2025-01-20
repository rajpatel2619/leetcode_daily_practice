class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> f(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                f[mat[i][j]] = make_pair(i, j);
            }
        }

        vector<int> a(m,0), b(n,0);
        for(int i=0;i<arr.size();i++){
            a[f[arr[i]].first]++;
            b[f[arr[i]].second]++;
            if(a[f[arr[i]].first]==n || b[f[arr[i]].second]==m)
                return i;
            
        }
        return -1;
    }
};