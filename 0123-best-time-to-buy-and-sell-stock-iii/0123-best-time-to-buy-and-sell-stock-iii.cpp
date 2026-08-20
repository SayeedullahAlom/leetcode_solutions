class Solution {
public:
    int f(int idx,int buy,vector<int>& prices, int cnt,vector<vector<vector<int>>> &dp){

        if(idx==prices.size()){
            return 0;
        }
        if(cnt<1){
            return 0;
        }

        if(dp[idx][buy][cnt]!=-1) return dp[idx][buy][cnt];

        int profit=0;
        if(buy && cnt>=1){
            profit=max(-prices[idx]+f(idx+1,0,prices,cnt,dp),f(idx+1,1,prices,cnt,dp));
        }
        else{
            profit=max(prices[idx]+f(idx+1,1,prices,cnt-1,dp),f(idx+1,0,prices,cnt,dp));
        }

        return dp[idx][buy][cnt] = profit;

    }

    int maxProfit(vector<int>& prices) {

        int n=prices.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3, -1)));

        return f(0,1,prices,2,dp);
    }
};