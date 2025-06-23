class Solution {
public:
    int func(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
       if(ind==0){
            return (amount%coins[ind]==0);
        }    
        
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        
        int ntake = func(ind-1,coins,amount,dp);
        int take = 0;
        if(coins[ind]<=amount) take = func(ind,coins,amount-coins[ind],dp);
        
        return dp[ind][amount] = take + ntake;
    }
    
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return func(n-1,coins,amount,dp);
        
        
        
        
        
        // //tabulation......
        // vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // for(int i=0;i<=amount;i++){
        //     dp[0][i]=(i%coins[0]==0);
        // }
        // for(int i=1;i<n;i++){
        //     for(int target = 0;target<=amount;target++){
        //         int ntake = dp[i-1][target];
        //         int take = 0;
        //         if(coins[i]<=target) take = dp[i][target-coins[i]];
        //         dp[i][target] = take + ntake;
        //     }
        // }
        // return dp[n-1][amount];
        
        
        
        
        
        
        //space opti......
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            prev[i]=(i%coins[0]==0);
        }
        for(int i=1;i<n;i++){
            for(int target = 0;target<=amount;target++){
                int ntake = prev[target];
                int take = 0;
                if(coins[i]<=target) take = curr[target-coins[i]];
                curr[target] = take + ntake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};