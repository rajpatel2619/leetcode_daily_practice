class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int last_min = prices[0];
        for(int i=1;i<prices.size();i++){
            max_profit = max(max_profit, prices[i]-last_min);
            last_min = min(last_min, prices[i]);
        }
        return max_profit;
    }
};