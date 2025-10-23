class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& its) {
        sort(its.begin(), its.end(), compare);
        int n = its.size();
        int count = 0;
        int end = its[0][1];
        for(int i=1;i<n;i++){
            if(its[i][0]<end){
                count++;
            }else end = its[i][1];
        }
        return count;
    }
};