class Solution {
public:
    int f(int n,int amount,vector<int>& coins,vector<vector<int>> &dp){
        
        if(n==0){
            if(amount%coins[0]==0) return amount/coins[0];
            return 1e9;
        }

        if(dp[n][amount]!=-1) return dp[n][amount];

        int not_take=0+f(n-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[n]){
            take=1+f(n,amount-coins[n],coins,dp);
        }

        return dp[n][amount] = min(take,not_take);
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n=coins.size();

        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        // int ans=f(n-1,amount,coins,dp);
        // if(ans>=1e9) return -1;

        // return ans;

        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){

                int not_take=dp[i-1][j];
                int take=1e9;
                if(j>=coins[i]){
                    take=1+dp[i][j-coins[i]];
                }

                dp[i][j] = min(take,not_take);       

            }
        }

        if(dp[n-1][amount]>=1e9) return -1;

        return dp[n-1][amount];
    }
};