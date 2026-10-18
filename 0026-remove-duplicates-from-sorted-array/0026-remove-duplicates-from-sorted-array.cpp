class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=200;
            }
        }

        sort(nums.begin(),nums.end());

        int ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=200){
                ans++;
            }
            else{
                break;
            }
        }

        return ans;   
    }
};