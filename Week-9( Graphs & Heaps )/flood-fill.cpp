/*# Approach
We use a **Depth-First Search (DFS)** approach to perform the flood fill. Starting from the given source pixel `(sr, sc)`, we recursively traverse in all 4 directions (up, right, down, left). If a neighboring pixel has the same initial color (`icolor`) and hasn't already been updated to the new `color`, we recursively call DFS on it and change its color.

We maintain a separate `ans` matrix initialized to the original `image` to avoid mutating the original input. The DFS stops once it reaches a pixel that either:
- Is out of bounds, or
- Has a different color than `icolor`, or
- Has already been colored with the new `color`.

This ensures we only fill connected pixels of the same original color.

# Complexity
- **Time complexity:**  
  $$O(m \times n)$$  
  In the worst case, all pixels in the image might have the same color and are connected. In such a case, each pixel will be visited once.

- **Space complexity:**  
  $$O(m \times n)$$  
  Due to the recursion stack in DFS and the copy of the `image` stored in `ans`, the space used can go up to `m * n` in the worst case.
*/


# Code
```cpp
class Solution {
public:
    void dfs(int row, int col, int color, int icolor,
             vector<vector<int>>& image, vector<vector<int>> & ans) {
        ans[row][col] = color;

        int m = image.size();
        int n = image[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                image[nrow][ncol] == icolor && ans[nrow][ncol] != color){
                    dfs(nrow, ncol, color, icolor, image, ans);
                }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int m = image.size();
        int n = image[0].size();
        int icolor = image[sr][sc];
        if (icolor == color) return image;  // optimization to avoid unnecessary work

        vector<vector<int>> ans = image;
        dfs(sr, sc, color, icolor, image, ans);
        return ans;
    }
};
