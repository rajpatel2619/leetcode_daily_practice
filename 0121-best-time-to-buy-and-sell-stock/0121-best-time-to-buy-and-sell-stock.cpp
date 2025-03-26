class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p = 0;
        int mini = prices[0];
        for(int i=1;i<n;i++){
            p = max(prices[i]-mini, p);
            mini = min(mini, prices[i]);
        }
        return p;
    }
};