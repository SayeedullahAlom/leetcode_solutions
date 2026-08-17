class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> original = board;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int count = 0;
                int x = i - 1;

                while (x <= i + 1) {
                    int y = j - 1;

                    while (y <= j + 1) {

                        if (x >= 0 && x < m &&
                            y >= 0 && y < n &&
                            !(x == i && y == j)) {

                            if (original[x][y] == 1) {
                                count++;
                            }
                        }

                        y++;
                    }

                    x++;
                }

                if (original[i][j] == 1 &&
                    (count < 2 || count > 3)) {
                    board[i][j] = 0;
                }
                else if (original[i][j] == 0 &&
                         count == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};