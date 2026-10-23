class Solution {
public:
    void f(int i, int n, vector<int> &vis, vector<vector<int>> &isConnected){
        queue<int> q;
        q.push(i);
        vis[i]=1;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int j=0;j<n;j++){
                if(isConnected[u][j]==1 and !vis[j]){
                    q.push(j);
                    vis[j]=1;
                }
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]!=1){
                ans++;
                f(i,n,vis,isConnected);
            }
        }
        return ans;
    }
};