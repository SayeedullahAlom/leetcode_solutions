class Solution {
public:
    int f(int i,int j1,int j2,int row,int col,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j1>col-1 || j2<0 || j2>col-1) return -1e9;

        if(i==row-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+grid[i][j2];
            }
        }

        if(dp[i][j1][j2]!=-1e9) return dp[i][j1][j2];

        int maxi=INT_MIN;

        for(int l=-1;l<=1;l++){
            for(int m=-1;m<=1;m++){
                int value=0;

                if(j1==j2){
                    value=grid[i][j1];
                }
                else{
                    value=grid[i][j1]+grid[i][j2];
                }

                value=value+f(i+1,j1+l,j2+m,row,col,grid,dp);

                maxi=max(value,maxi);
            }
        }

        return dp[i][j1][j2]=maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1e9)));

        return f(0,0,c-1,r,c,grid,dp);
    }
};