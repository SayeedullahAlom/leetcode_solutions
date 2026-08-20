class Solution {
public:
    int f(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp){

        if(idx==prices.size()){
            return 0;
        }

        if(dp[idx][buy]!=-1e9) return dp[idx][buy];

        int profit=0;
        if(buy){
            profit=max(-prices[idx]+f(idx+1,0,prices,dp),f(idx+1,1,prices,dp));
        }
        else{
            profit=max(prices[idx]+f(idx+1,1,prices,dp),f(idx+1,0,prices,dp));
        }

        return dp[idx][buy]=profit;

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1e9));
        // return f(0,1,prices,dp);
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){

                int profit=0;

                if(j){
                    profit=max(-prices[i]+dp[i][0],dp[i+1][1]);
                }
                else{
                    profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
                }

                dp[i][j]=profit;

            }
        }

        return dp[0][1];

    }
};