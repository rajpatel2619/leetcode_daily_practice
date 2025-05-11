class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, left = 0, right = n-1, bottom = m-1;
        vector<int> res;
        while(top<=bottom and left<=right){
            //top
            for(int j=left;j<=right;j++)
                res.push_back(matrix[top][j]);
            top++;
            //right
            for(int i=top;i<=bottom;i++)
                res.push_back(matrix[i][right]);
            right--;
            //bottom
            if(top<=bottom){
                for(int j=right;j>=left;j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }
            //left
            if(left<=right){
                for(int i=bottom;i>=top;i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};