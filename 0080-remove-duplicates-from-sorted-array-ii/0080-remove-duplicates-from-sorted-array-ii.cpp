class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()<3) return nums.size();

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                nums[i]=1e9;
            }
        }

        sort(nums.begin(),nums.end());

        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=1e9){
                ans++;
            }
            else{
                break;
            }
        }

        return ans;
    }
};