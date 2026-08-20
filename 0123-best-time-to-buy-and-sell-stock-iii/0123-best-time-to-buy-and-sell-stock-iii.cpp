class Solution {
public:
    int f(int idx,int buy,vector<int>& prices, int cnt,vector<vector<vector<int>>> &dp){

        if(idx==prices.size()){
            return 0;
        }
        if(cnt==0){
            return 0;
        }

        if(dp[idx][buy][cnt]!=-1) return dp[idx][buy][cnt];

        int profit=0;
        if(buy){
            profit=max(-prices[idx]+f(idx+1,0,prices,cnt,dp),f(idx+1,1,prices,cnt,dp));
        }
        else{
            profit=max(prices[idx]+f(idx+1,1,prices,cnt-1,dp),f(idx+1,0,prices,cnt,dp));
        }

        return dp[idx][buy][cnt] = profit;

    }

    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3, -1)));

        // return f(0,1,prices,2,dp);

        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                dp[i][j][0]=0;
            }
        }

        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                dp[n][i][j]=0;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=1;k<=2;k++){
                    int profit=0;
                    if(j){
                        profit=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
                    }
                    else{
                        profit=max(prices[i]+dp[i+1][1][k-1],dp[i+1][0][k]);
                    }

                    dp[i][j][k] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};