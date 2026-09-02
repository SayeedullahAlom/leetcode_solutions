class Solution {
public:
    void f(int idx,vector<int>& candidates, int target, vector<vector<int>> &ans,int sum,vector<int> &ds){

        
        if(sum==target){
            ans.push_back(ds);
            return;
        }

        if(idx==candidates.size() || sum>target){
            return ;
        }
            
        if(sum+candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            f(idx,candidates,target,ans,sum+candidates[idx],ds);
            ds.pop_back();
        }
        

        f(idx+1,candidates,target,ans,sum,ds);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0,candidates,target,ans,0,ds);
        return ans;
    }
};