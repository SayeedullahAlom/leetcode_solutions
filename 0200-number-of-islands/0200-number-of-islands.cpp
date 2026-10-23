class Solution {
public:
    void f(int i,int j,int m,int n,vector<vector<int>>& vis,vector<vector<char>>& grid){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]=='0') return ;

        vis[i][j]=1;

        vector<int> x={0,1,0,-1};
        vector<int> y={1,0,-1,0};

        for(int d=0;d<x.size();d++){
            f(i+x[d],j+y[d],m,n,vis,grid);
        }

        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    f(i,j,m,n,vis,grid);
                }
            }
        }
        return ans;
    }
};