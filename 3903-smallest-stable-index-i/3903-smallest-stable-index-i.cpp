class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> mini(n);
        int mi=INT_MAX;
        for(int i=n-1;i>=0;i--){
            mi=min(nums[i],mi);
            mini[i]=mi;
        }

        int ma=INT_MIN;
        for(int i=0;i<nums.size();i++){
            ma=max(ma,nums[i]);
            mini[i]=ma-mini[i];
        }

        int ans=-1;

        for(int i=0;i<n;i++){
            if(mini[i]<=k){
                return i;
            }
        }

        return ans;
    }
};