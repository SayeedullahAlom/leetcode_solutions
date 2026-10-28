class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
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

        return ans;
    }
};