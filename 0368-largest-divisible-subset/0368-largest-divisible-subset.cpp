class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n=nums.size();

        sort(nums.begin(),nums.end());

        vector<int> v(n,1);
        vector<int> prev(n,-1);
        vector<int> ans;

        for(int i=1;i<n;i++){
            int pre=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and v[j]+1>v[i]){
                    v[i]=v[j]+1;
                    pre=j;
                }
            }

            prev[i]=pre;
        }

        int previous=0;
        for(int i=1;i<n;i++){
            if(v[i]>v[previous]){
                previous=i;
            }
        }

        while(previous!=-1){
            ans.push_back(nums[previous]);
            previous=prev[previous];
        }

        return ans;
    }
};