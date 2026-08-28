class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<pair<int,int>> v(n,{1,1});

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && v[i].first<v[j].first+1){
                    v[i].first=v[j].first+1;
                    v[i].second = v[j].second;
                }
                else if(nums[i]>nums[j] && v[i].first==v[j].first+1){
                    v[i].second+=v[j].second;
                }
            }
        }

        int prev=0;
        for(int i=1;i<n;i++){
            if(v[i].first>v[prev].first){
                prev=i;
            }
        }

        int ans=0;

        for(int i=0;i<n;i++){
            if(v[i].first==v[prev].first){
                ans+=v[i].second;
            }
        }

        return ans;
    }
};