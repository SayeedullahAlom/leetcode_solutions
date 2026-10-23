class Solution {
public:
    int f(int n,int target,vector<int>& nums, vector<vector<int>> &dp){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }

        if(dp[n][target]!=-1) return dp[n][target];

        int not_take=f(n-1,target,nums,dp);
        int take=0;
        if(target>=nums[n])
            take=f(n-1,target-nums[n],nums,dp);

        return dp[n][target]=take+not_take;
    }
    int findTargetSumWays(vector<int>& nums, int diff) {
        int n=nums.size();
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }

        if(abs(diff)>total_sum || (total_sum-diff)%2!=0) return 0;

        int target=(total_sum-diff)/2;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return f(n-1,target,nums,dp);
    }
};