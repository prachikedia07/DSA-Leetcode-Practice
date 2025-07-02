/*# Approach
Imagine you're solving a puzzle: you try a value, go deeper, and if everything works out — great!
Otherwise, undo and try another.
So we:
Try placing a number (ch) at the current cell.
Call solve() to check: can we fill the rest of the board from here onward?
If that path leads to a solution → ✅ return true
If not → ❌ backtrack (board[row][col] = '.') and try next digit*/



# Code
```cpp []
class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, row, col, ch)) {
                            board[row][col] = ch;
                            if (solve(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++)
            if (board[i][col] == ch || board[row][i] == ch ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) {
                return false;
            }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};
```
