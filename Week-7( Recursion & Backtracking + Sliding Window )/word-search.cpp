# Code
```cpp []
class Solution {
public:
    bool dfs(int index, int row, int col, vector<vector<char>>& board,
             string word) {
        if (index == word.size())
            return true;
        if (row < 0 || col < 0 || row >= board.size() ||
            col >= board[0].size() || board[row][col] != word[index])
            return false;
        char temp = board[row][col];
        board[row][col] = '#';
        bool found = dfs(index + 1, row + 1, col, board, word) ||
                     dfs(index + 1, row - 1, col, board, word) ||
                     dfs(index + 1, row, col + 1, board, word) ||
                     dfs(index + 1, row, col - 1, board, word);
        board[row][col] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();    // rows
        int n = board[0].size(); // columns
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(0, i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};
```
