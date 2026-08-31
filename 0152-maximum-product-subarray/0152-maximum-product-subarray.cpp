class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int ans=-1e9;
        // for(int i=0;i<nums.size();i++){
        //     int prod=1;
        //     for(int j=i;j<nums.size();j++){
        //         prod*=nums[j];
        //         ans=max(prod,ans);
        //     }
        // }
        // return ans;

        int ans=INT_MIN;

        int currMax=1;
        int currMin=1;
        for(auto num:nums){
            int temp=num*currMax;
            currMax=max(max(temp,num*currMin),num);
            currMin=min(min(temp,num*currMin),num);
            ans=max(ans,currMax);
        }

        return ans;
    }
};