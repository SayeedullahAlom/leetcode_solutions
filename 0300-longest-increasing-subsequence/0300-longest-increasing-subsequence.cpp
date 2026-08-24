class Solution {
public:
    int f(int i,vector<int>& nums, int prev,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int not_take=f(i+1,nums,prev,dp);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+f(i+1,nums,i,dp);
        }

        return dp[i][prev+1]=max(take,not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {

        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        // return f(0,nums,-1,dp);

        for(int i=0;i<n+1;i++){
            dp[n][i]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int not_take=dp[i+1][prev+1];
                int take=0;
                if(prev==-1 || nums[i]>nums[prev]){
                    take=1+dp[i+1][i+1];
                }

                dp[i][prev+1]=max(take,not_take);
            }
        }

        return dp[0][0];
    }
};