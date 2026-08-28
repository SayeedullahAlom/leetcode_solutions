class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();

        vector<int> v1(n,1);
        vector<int> v2(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && v1[i]<v1[j]+1){
                    v1[i]=v1[j]+1;
                }
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j] and v2[i]<v2[j]+1){
                    v2[i]=v2[j]+1;
                }
            }
        }

        int maxi=0;

        for(int i=1;i<n-1;i++){
            if(v1[i]>1 && v2[i]>1){
                maxi=max(maxi,v1[i]+v2[i]-1);
            }
        }

        return n-maxi;
    }
};