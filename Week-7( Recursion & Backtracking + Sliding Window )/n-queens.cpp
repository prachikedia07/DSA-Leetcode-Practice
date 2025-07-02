# Code
```cpp []
class Solution {
public:
    void solve(int col, vector<string>& board, vector<vector<string>>& res,
               int n, vector<int>& leftrow, vector<int>& upperdia,
               vector<int>& lowerdia) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 && lowerdia[row + col] == 0 &&
                upperdia[n - 1 + col - row] == 0) {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerdia[row + col] = 1;
                upperdia[n - 1 + col - row] = 1;
                solve(col + 1, board, res, n, leftrow, upperdia, lowerdia);

                board[row][col] = '.';
                leftrow[row] = 0;
                lowerdia[row + col] = 0;
                upperdia[n - 1  + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<int> leftrow(n, 0);
        vector<int> upperdia(2 * n - 1, 0);
        vector<int> lowerdia(2 * n - 1, 0);
        solve(0, board, res, n, leftrow, upperdia, lowerdia);
        return res;
    }
};
```
