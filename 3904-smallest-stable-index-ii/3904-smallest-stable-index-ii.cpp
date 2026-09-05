class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n=nums.size();

        long long m=INT_MAX;
        vector<long long> mini(n);
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]<m){
                m=nums[i];
            }
            mini[i]=m;
        }

        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini[i]=maxi-mini[i];
        }

        int ans=-1;

        for(int i=0;i<n;i++){
            if(mini[i]<=k){
                return i;
                break;
            }
        }

        return ans;
    }
};