class Solution {
public:
    unordered_map<int, long long> dp;
    long long solve(int ind, int n, vector<vector<int>>&arr, long long points){
        if(ind>=n)
            return 0;
        if(dp.find(ind)!=dp.end()) return dp[ind];
        long long take = arr[ind][0]+solve(ind+arr[ind][1]+1, n, arr, points+arr[ind][0]);
        long long ntake = solve(ind+1, n, arr, points);
        return dp[ind] =max(take, ntake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        return solve(0, n, questions, 0);
    }
};