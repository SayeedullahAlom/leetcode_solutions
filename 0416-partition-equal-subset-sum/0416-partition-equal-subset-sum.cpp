class Solution {
public:
    bool f(int n,int target,vector<int>& nums,vector<vector<int>> &dp){
        if(target==0) return true;
        if(n==0) return nums[0]==target;

        if(dp[n][target]!=-1) return dp[n][target];

        int not_take=f(n-1,target,nums,dp);
        int take=false;
        if(target>=nums[n]){
            take=f(n-1,target-nums[n],nums,dp);
        }

        return dp[n][target] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        int target=0;
        if(sum%2!=0){
            return false;
        }
        else{
            target=sum/2;
        }

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return f(n-1,target,nums,dp);


    }
};