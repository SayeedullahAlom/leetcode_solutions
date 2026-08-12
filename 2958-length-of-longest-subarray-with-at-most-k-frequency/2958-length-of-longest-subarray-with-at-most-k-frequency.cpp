class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        if(k==0) return 0;
        int n=nums.size();
        unordered_map<int,int> m;
        int l=0;
        int r=0;
        int maxi=1;
        while(r<n){
            m[nums[r]]++;
            if(m[nums[r]]<=k){
                r++;
            }
            else{
                maxi=max(maxi,r-l);
                while(nums[l]!=nums[r]){
                    m[nums[l]]--;
                    l++;
                }
                m[nums[l]]--;
                l++;
                r++;
            }
        }

        return max(maxi,r-l);
    }
};