class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<vector<int>> arr(10,vector<int>(10,0));
        int c = 0;
        for(auto p:dominoes){
            c+=arr[p[0]][p[1]];
            arr[p[0]][p[1]]++;
            if(p[0]!=p[1])
                arr[p[1]][p[0]]++;
        }
        return c;
    }
};