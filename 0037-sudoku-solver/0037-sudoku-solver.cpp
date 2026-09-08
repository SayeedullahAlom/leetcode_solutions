class Solution {
public:

    bool isSafe(int r,int c,vector<vector<char>>& board,char ch){
        for(int i=0;i<9;i++){
            if(board[r][i]==ch){
                return false;
            }
            if(board[i][c]==ch){
                return false;
            }
            if(board[3*(r/3)+i/3][3*(c/3)+i%3]==ch){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i=i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){

                    for(char ch='1';ch<='9';ch++){

                        if(isSafe(i,j,board,ch)){
                            board[i][j]=ch;

                            if(solve(board)==true) return true;
                            else{
                                board[i][j]='.';
                            }
                        }

                    }

                    return false;

                }
                
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};