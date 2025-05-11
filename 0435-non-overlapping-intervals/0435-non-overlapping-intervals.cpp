class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int>&b){
            return a[1]<b[1];
        });
        int k = 0;
        int count = 0;
        for(auto el:intervals){
            cout<<el[0]<<" "<<el[1]<<endl;
        }
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<intervals[k][1])
                count++;
            else k = i;
        }
        return count;
    }
};