class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        int ind = 0;
        vector<vector<int>> meets;
        meets.push_back(meetings[0]);
        for(int i=1;i<n;i++){
            if(meets[ind][1]>=meetings[i][0]){
                meets[ind][1] = max(meets[ind][1], meetings[i][1]);
            }else{
                meets.push_back(meetings[i]);
                ind++;
            }
        }
        
        for(auto e:meets)
            cout<<e[0]<<" "<<e[1]<<endl;
        ind = meets.size();
        long long count = 0;
        if(meets[0][0]!=1)
            count+=meets[0][0]-1;
        for(int i=1;i<ind;i++){
            if(meets[i][0]-meets[i-1][1]>1){
                count+=(meets[i][0]-meets[i-1][1]-1);
            }
        }
        if(meets[ind-1][1]<days)
            count+=(days-meets[ind-1][1]);
        return count;
    }
};