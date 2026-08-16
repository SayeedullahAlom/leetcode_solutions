class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;

        int mini=INT_MAX;
        int sum=0;

        while(r<n){
            sum+=nums[r];
            if(sum<target){
                r++;
            }
            else{
                mini=min(mini,r-l+1);
                while(sum>=target){
                    sum-=nums[l];
                    l++;
                    if(sum>=target){
                        mini=min(mini,r-l+1);
                    }   
                }
                r++;
            }
        }

        if(mini==INT_MAX){
            return 0;
        }

        return mini;

    }
};