# Code
```cpp []
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // marked as visited
        vector<pair<int, int>> dirs = {{1, 0},  {0, 1},  {1, 1},  {1, -1},
                                       {-1, 1}, {-1, 0}, {0, -1}, {-1, -1}};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int step = grid[x][y];
            if (x == n - 1 && y == n - 1)
                return step;
            for (auto [dx, dy] : dirs) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                    grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] =
                        step + 1; // mark visited & store step count }
                }
            }
        }
            return -1;
            }
        };
```
