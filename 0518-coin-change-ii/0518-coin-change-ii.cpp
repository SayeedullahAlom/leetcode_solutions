class Solution {
public:
    int f(int n,int amount,vector<int>& coins,vector<vector<int>> &dp){

        if(n==0){
            if(amount==0) return 1;
            if(amount%coins[0]==0) return 1;
            return 0;
        }

        if(dp[n][amount]!=-1) return dp[n][amount];

        int not_take=f(n-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[n]){
            take=f(n,amount-coins[n],coins,dp);
        }

        return dp[n][amount] = take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }
};