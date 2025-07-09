/*# Approach
We use **Breadth-First Search (BFS)** to find connected components (islands) in a 2D grid. Each cell in the grid represents either land (`'1'`) or water (`'0'`). An island is formed by connecting adjacent lands horizontally or vertically.

Here's the approach:
1. Traverse every cell in the grid.
2. When an unvisited land cell (`'1'`) is found, perform a BFS from that cell.
3. During BFS, mark all connected land cells as visited using a `vis` matrix.
4. Each BFS traversal corresponds to one island, so increment the island count.
5. Return the total count of islands found.

---

# Complexity

- **Time complexity**:  
  $$O(m \times n)$$  
  Every cell is visited once. BFS also runs in linear time relative to the number of nodes (cells).

- **Space complexity**:  
  $$O(m \times n)$$  
  For the visited matrix `vis` and in the worst case, the queue can hold all land cells in one island.

---*/

# Code
```cpp
class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});

        int m = grid.size();    // rows
        int n = grid[0].size(); // columns

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse horizontal and vertical neighbours
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();    // rows
        int n = grid[0].size(); // columns
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (!vis[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};
