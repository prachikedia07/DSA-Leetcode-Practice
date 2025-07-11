/*# Approach
1. Start DFS from all Pacific-border cells -> mark where water can flow to Pacific
2. Start DFS from all Atlantic-border cells -> mark where water can flow to Atlantic
3. Find cells that can flow to both


# Complexity
- Time complexity:
O(m * n)

- Space complexity:
O(m + n)*/

# Code
```cpp []
class Solution {
public:
void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int i, int j){
     int m = heights.size();
        int n = heights[0].size();
        ocean[i][j] = true;
        vector<pair<int,int>> directions = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        for(auto [di, dj] : directions){
            int ni = i + di;
            int nj = j + dj;
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && !ocean[ni][nj] && heights[ni][nj] >= heights[i][j] )
            dfs(heights, ocean, ni, nj);
        }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < n; i++) { // traversing top row
            dfs(heights, pacific, 0, i);
        }
        for (int j = 0; j < m; j++) { // traversing left column
            dfs(heights, pacific, j, 0);
        }
        for (int i = 0; i < m; i++) {
            dfs(heights, atlantic, i, n - 1); // right column
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, atlantic, m - 1, j); // bottom row
        }
        vector<vector<int>> res;
        for(int i = 0; i<m ;i++){
            for(int j = 0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j])
                res.push_back({i,j});
            }
        }
        return res;
    }
};
```
