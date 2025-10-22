class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        int sp = cost[0], p = cost[1];
        for(int i=2;i<=n;i++){
            int curr = cost[i]+min(sp, p);
            sp = p;
            p = curr;
        }
        return p;
    }
};