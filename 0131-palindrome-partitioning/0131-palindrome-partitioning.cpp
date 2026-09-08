class Solution {
public:
    bool isPalindrome(int l,int r,string s){
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    void f(int i,string s,vector<vector<string>> &ans,vector<string> &path){
        if(i==s.size()){
            ans.push_back(path);
            return;
        }

        for(int idx=i;idx<s.size();idx++){
            if(isPalindrome(i,idx,s)){
                path.push_back(s.substr(i,idx-i+1));
                f(idx+1,s,ans,path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        f(0,s,ans,path);
        return ans;
    }
};