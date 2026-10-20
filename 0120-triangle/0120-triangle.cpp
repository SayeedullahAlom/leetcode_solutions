class Solution {
public:
    int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(j>i) return 1e9;
        if(i==n-1) return triangle[i][j];

        if(dp[i][j]!=1e9) return dp[i][j];

        int down=triangle[i][j]+f(i+1,j,n,triangle,dp);
        int dia=triangle[i][j]+f(i+1,j+1,n,triangle,dp);

        return dp[i][j]=min(down,dia);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));
        // return f(0,0,n,triangle,dp);

        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){

                int down=triangle[i][j]+dp[i+1][j];
                int dia=triangle[i][j]+dp[i+1][j+1];  

                dp[i][j]=min(down,dia);              
            }
        }

        return dp[0][0];
    }
};