class Solution {
public:
    long long dsum(int num){
        long long ans = 0;
        while(num){
            ans+=(num%10);
            num/=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<long long, vector<int>> mp;
        int maxi = -1;
        for(auto &e:nums){
            long long key = dsum(e);
            // if(mp.find(key)!=mp.end()){
                mp[key].push_back(e);
        }
        for(auto e:mp){
            if(e.second.size()>=2){
                sort(e.second.begin(), e.second.end());
                maxi = max(maxi, *rbegin(e.second)+ *next(rbegin(e.second)));
            }
            
        }
        // cout<<e.first<<" "<<e.second.first<<" "<<e.second.second<<endl;
        return maxi;
    }
};