class Solution {
public:
    bool rem(pair<int, int> st, pair<int, int> at, int target){
        if(st.second<at.second) return true;
        double a= (target-at.first)/(at.second*1.0);
        double  b= (target-st.first)/(st.second*1.0);
        return a<b;
    }
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int,double>> arr;
        //pos, time
        for(int i=0;i<n;i++){
            double time = (target-pos[i])/(1.0*speed[i]);
            arr.push_back({pos[i], time});
        }
        sort(arr.rbegin(), arr.rend());

        int count = 0;
        double maxi = 0;
        for(auto p:arr){
            if(p.second>maxi){
                count++;
                maxi = p.second;
            }
        }
        return count;
    }
};