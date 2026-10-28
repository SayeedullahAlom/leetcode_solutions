class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();

        int i=0;
        int j=n-1;

        int ans=n;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(nums[mid]>=target){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        if(ans==n || nums[ans]!=target) return {-1,-1};

        i=0;
        j=n-1;

        int ans2=n;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(nums[mid]>target){
                ans2=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }

        return {ans,ans2-1};
    }
};