class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> m;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;

                if(m[ board[i][j]]>0){
                    return false;
                }

                m[board[i][j]]++;
            }
            m.clear();
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;

                if(m[board[j][i]]>0){
                    return false;
                }
                
                m[board[j][i]]++;
            }
            m.clear();
        }

        for (int block = 0; block < 9; block++) {
            int rowOffset = (block / 3) * 3;
            int colOffset = (block % 3) * 3;

            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    char val = board[rowOffset + r][colOffset + c];
                    if (val == '.') continue;
                    if (m[val] > 0) return false;
                    m[val]++;
                }
            }
            m.clear();
        }

        return true;
        
    }
};