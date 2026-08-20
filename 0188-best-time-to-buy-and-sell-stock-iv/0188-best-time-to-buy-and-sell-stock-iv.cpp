class Solution {
public:
    int f(int i,int buy,int k,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(i==prices.size()){
            return 0;
        }

        if(k==0){
            return 0;
        }

        if(dp[i][buy][k]!=-1) return dp[i][buy][k];

        int profit=0;

        if(buy){
            profit=max(-prices[i]+f(i+1,0,k,prices,dp),f(i+1,1,k,prices,dp));
        }
        else{
            profit=max(prices[i]+f(i+1,1,k-1,prices,dp),f(i+1,0,k,prices,dp));
        }

        return dp[i][buy][k]= profit;

    }

    int maxProfit(int k, vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        // return f(0,1,k,prices,dp);

        for(int i=0;i<=n;i++){
            for(int j=0;j<=1;j++){
                dp[i][j][0]=0;
            }
        }

        for(int i=0;i<=1;i++){
            for(int j=0;j<=k;j++){
                dp[n][i][j]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int l=1;l<=k;l++){

                    int profit=0;

                    if(buy){
                        profit=max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][l-1],dp[i+1][0][l]);
                    }

                    dp[i][buy][l]= profit;
                }
            }
        }

        return dp[0][1][k];

    }
};