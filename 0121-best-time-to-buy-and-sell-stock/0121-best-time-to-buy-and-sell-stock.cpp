class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mp = 0;
        int mini = prices[0];
        for(int j=1;j<n;j++){
            mp = max(mp, prices[j]-mini);
            mini = min(mini, prices[j]);
        }
        return mp;
    }
};