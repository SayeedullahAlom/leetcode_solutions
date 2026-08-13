class Solution {
public:
    int f(int n, vector<int>& nums, int target){
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target+nums[0]==0 || target-nums[0]==0) return 1;
            else return 0;
        }

        int m=f(n-1,nums,target-nums[n]);
        int p=f(n-1,nums,target+nums[n]);

        return m+p;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,nums,target);
    }
};