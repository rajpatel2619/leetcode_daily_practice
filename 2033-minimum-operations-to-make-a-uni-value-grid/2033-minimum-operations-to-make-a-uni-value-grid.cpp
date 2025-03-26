class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &r:grid){
            arr.insert(arr.end(), r.begin(), r.end());
        }
        sort(arr.begin(), arr.end());
        int e = arr[0]%x;
        for(auto &el:arr)
            if(el%x!=e)
                return -1;
        int mid = arr.size()/2;
        int ans = 0;
        for(auto &el:arr){
            ans+=abs(el-arr[mid])/x;
        }
        return ans;
    }
};