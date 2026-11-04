class Solution {
public:

    void f(int i, int j, int m, int n, vector<vector<char>>& board, vector<vector<int>> &vis){

        vis[i][j]=1;

        vector<int> x={-1,0,1,0};
        vector<int> y={0,1,0,-1};

        for(int k=0;k<4;k++){
            int dx=i+x[k];
            int dy=j+y[k];

            if(dx>=0 && dx<m && dy>=0 && dy<n && !vis[dx][dy] && board[dx][dy]=='O'){
                f(dx,dy,m,n,board,vis);
            }
        }

        return ;
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i=0;i<n;i++){
            if(!vis[0][i] and board[0][i]=='O'){
                f(0,i,m,n,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[m-1][i] and board[m-1][i]=='O'){
                f(m-1,i,m,n,board,vis);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[i][0] and board[i][0]=='O'){
                f(i,0,m,n,board,vis);
            }
        }

        for(int i=0;i<m;i++){
            if(!vis[i][n-1] and board[i][n-1]=='O'){
                f(i,n-1,m,n,board,vis);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

        return ;
    }
};