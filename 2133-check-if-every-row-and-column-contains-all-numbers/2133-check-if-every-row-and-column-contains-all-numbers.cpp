class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> r(n,0), c(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i]+=matrix[i][j];
                c[i]+=matrix[i][j];
            }
        }
        int sum = (n*(n+1))/2;
        for(int i=0;i<n;i++){
            if(r[i]!=sum || c[i]!=sum)
                return false;
        }
        return true;
    }
};