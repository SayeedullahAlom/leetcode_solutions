class Solution {
public:
    void f(int i,int n,int k,vector<int> &ds,vector<vector<int>> &ans){
        if(ds.size()==k){
            ans.push_back(ds);
            return;
        }

        if(i>n) return;
   
        ds.push_back(i);
        f(i+1,n,k,ds,ans);
        ds.pop_back();
        f(i+1,n,k,ds,ans);

        return ;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> ds;
        vector<vector<int>> ans;

        f(1,n,k,ds,ans);

        return ans;
    }
};