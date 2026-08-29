class Solution {
public:
    int f(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini=1e9;
        for(int k=i;k<=j;k++){
            int costs=cuts[j+1]-cuts[i-1]+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini=min(mini,costs);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin()+0,0);
        cuts.push_back(n);
        int s=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(s,vector<int>(s,-1));
        return f(1,s-2,cuts,dp);
    }
};