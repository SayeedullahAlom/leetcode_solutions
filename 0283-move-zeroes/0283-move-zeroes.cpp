class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                nums.erase(nums.begin()+j);
                count++;
            }
            else{
                j++;
            }
        }

        for(int i=0;i<count;i++){
            nums.push_back(0);
        }
    }
};