class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int h=0;

        if(n%2==0){
            h=n/2;
        }
        else{
            h=n/2+1;
        }

        vector<int> temp;

        int l=0;
        int r=n-1;

        while(h>0){
            if(abs(nums[l])>abs(nums[r])){
                temp.push_back(nums[l]);
                nums[l]=0;
                l++;
            }
            else{
                temp.push_back(nums[r]);
                nums[r]=0;
                r--;
            }

            h--;
        }

        long long sum_s=0;
        long long sum_l=0;

        for(int i=0;i<nums.size();i++){
            sum_s+=nums[i]*nums[i];
        }

        for(int i=0;i<temp.size();i++){
            sum_l+=temp[i]*temp[i];
        }

        return sum_l-sum_s; 
    }
};