class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& dp) {
        if (f == 0 || f == 1 || e == 1) return f;
        if (dp[e][f] != -1) return dp[e][f];

        int low = 1, high = f, res = f;
        while (low <= high) {
            int mid = (low + high) / 2;
            int breakCase = solve(e - 1, mid - 1, dp);
            int noBreakCase = solve(e, f - mid, dp);
            int temp = 1 + max(breakCase, noBreakCase);

            // Minimize the worst case
            if (breakCase > noBreakCase) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            res = min(res, temp);
        }
        return dp[e][f] = res;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};
