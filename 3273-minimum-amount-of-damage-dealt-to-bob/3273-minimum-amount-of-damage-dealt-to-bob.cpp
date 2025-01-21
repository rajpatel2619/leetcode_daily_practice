class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<int, int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {damage[i], ceil((double)health[i]/power)};
        }
        sort(arr.begin(), arr.end(), [](auto &p, auto &q){
            return (long long)p.first*q.second>(long long)p.second*q.first;
        });

        long long td = 0, t = 0;
        for(int i=0;i<n;i++){
            td+=arr[i].first*(arr[i].second+t);
            t+=arr[i].second;
        }
        return td;
    }
};