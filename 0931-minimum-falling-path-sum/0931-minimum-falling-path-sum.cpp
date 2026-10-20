class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>matrix.size()-1){
            return 1e9;
        }

        if(i==matrix.size()-1){
            return matrix[i][j];
        }

        if(dp[i][j]!=1e9) return dp[i][j];

        int down=matrix[i][j]+f(i+1,j,matrix,dp);
        int left=matrix[i][j]+f(i+1,j-1,matrix,dp);
        int right=matrix[i][j]+f(i+1,j+1,matrix,dp);

        return dp[i][j] = min({down,left,right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();

        vector<vector<int>> dp(n,vector<int>(n,1e9));

        int mini=INT_MAX;

        for(int i=0;i<n;i++){
            mini=min(mini,f(0,i,matrix,dp));
        }

        return mini;


        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }

        for(int i=n-2;i>=0;i++){
            for(int j=n-1;j>=0;j++){

                int down=matrix[i][j]+dp[i+1][j];
                int left=1e9;
                int right=1e9;

                if(j>0)
                    left=matrix[i][j]+dp[i+1][j-1];
                if(j<n-1){
                    right=matrix[i][j]+dp[i+1][j+1];
                }

                dp[i][j]=min({down,left,right});

            }
        }

        int ans=INT_MAX;
        
        for(int i=0;i<n;i++){
            ans=min(ans,dp[0][i]);
        }

        return ans;


    }
};