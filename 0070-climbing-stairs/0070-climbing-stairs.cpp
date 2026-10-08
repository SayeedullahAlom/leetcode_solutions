class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n==1 || n==2) return n;

        if(dp[n]!=-1) return dp[n];

        int one_step=f(n-1,dp);
        int two_step=f(n-2,dp);

        return dp[n]=one_step+two_step;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }
};