class Solution {
public:
    void f(int i, int j, int m, int n, vector<vector<int>>& board, vector<vector<int>> &vis){

        vis[i][j]=1;

        vector<int> x={-1,0,1,0};
        vector<int> y={0,1,0,-1};

        for(int k=0;k<4;k++){
            int dx=i+x[k];
            int dy=j+y[k];

            if(dx>=0 && dx<m && dy>=0 && dy<n && !vis[dx][dy] && board[dx][dy]==1){
                f(dx,dy,m,n,board,vis);
            }
        }

        return ;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            if(!vis[0][i] and grid[0][i]==1){
                f(0,i,m,n,grid,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[m-1][i] and grid[m-1][i]==1){
                f(m-1,i,m,n,grid,vis);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[i][0] and grid[i][0]==1){
                f(i,0,m,n,grid,vis);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[i][n-1] and grid[i][n-1]==1){
                f(i,n-1,m,n,grid,vis);
            }
        }

        int ans=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }

        return ans;
    }
};