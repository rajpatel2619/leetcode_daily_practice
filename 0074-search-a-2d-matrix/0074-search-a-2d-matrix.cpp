class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]>target) r = mid-1;
            else l = mid+1;
        }
        
        return r>=0 and binary_search(matrix[r].begin(), matrix[r].end(), target);
    }
};