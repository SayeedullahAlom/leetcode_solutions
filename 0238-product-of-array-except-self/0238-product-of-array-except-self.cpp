class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<long long> left(n);
        vector<long long> right(n);
        vector<int> ans(n);


        long long prod1=1;
        long long prod2=1;

        for(int i=0;i<n;i++){
            if(i==0){
                prod1*=nums[i];
                left[i]=prod1;
            }
            else{
                prod1*=nums[i];                
                left[i]=prod1;
            }
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                prod2*=nums[i];
                right[i]=prod2;
            }
            else{
                prod2*=nums[i];
                right[i]=prod2;
            }
        }

        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=right[i+1];
            }
            else if(i==nums.size()-1){
                ans[i]=left[i-1];
            }
            else{
                ans[i]=left[i-1]*right[i+1];
            }
        }

        return ans;

    }
};