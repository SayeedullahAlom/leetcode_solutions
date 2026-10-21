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

        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        vector<vector<int>> dp(n,vector<int>(target+1,0));

        // return f(n-1,target,nums,dp);

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if(nums[0]<=target){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){

                int not_take=dp[i-1][j];
                int take=false;
                if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                }

                dp[i][j] = take || not_take;

            }
        }

        return dp[n-1][target];

    }
};