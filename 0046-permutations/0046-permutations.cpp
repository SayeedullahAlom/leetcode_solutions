class Solution {
public:

    void f(vector<int>& nums, vector<int> &ds, vector<int> &freq, vector<vector<int>> &ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                ds.push_back(nums[i]);
                freq[i]=1;
                f(nums,ds,freq,ans);
                freq[i]=0;
                ds.pop_back();
            }
        }

        return ;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> freq;

        for(int i=0;i<nums.size();i++){
            freq.push_back(0);
        }

        f(nums,ds,freq,ans);

        return ans;
    }
};