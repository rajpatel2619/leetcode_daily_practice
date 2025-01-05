class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        for(auto &l:logs)
            l[1]--;
        sort(logs.begin(), logs.end());
        vector<int> pref(101, 0);
        for(auto &l:logs){
            int lt = l[0];
            int rt = l[1];
            while(lt<=rt){
                pref[lt-1950]++;
                lt++;
            }
        }
        int mx = 0, mxi = 0;
        for(int i=0;i<101;i++){
            if(pref[i]>mx){
                mx = pref[i];
                mxi = i;
            }
        }
        return mxi+1950;
    }
};