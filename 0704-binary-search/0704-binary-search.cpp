class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;

        while(l<=r){
            int h=l+(r-l)/2;
            if(nums[h]==target){
                return h;
            }
            if(nums[h]>target){
                r=h-1;
            }
            else{
                l=h+1;
            }
        }
        return -1;
    }
};