/*# Approach
This structure allows us to treat the entire matrix as a flattened sorted 1D array and apply binary search on it becuase:
> Integers in each row are sorted in ascending order.
> The first integer of each row is greater than the last integer of the previous row.
So to solve the problem we,
  -Treat the 2D matrix as a 1D array of size m * n, where m is the number of rows and n is the number of columns.
  -For a mid index in the 1D view, compute the actual row and column in the 2D matrix using:
     row = mid / n
     col = mid % n
  -Use binary search to compare the element at matrix[row][col] with the target.
  -If equal, return true. If less than target, move low up. If greater, move high down.
  -Return false if the target is not found.

# Complexity
- Time complexity:
O(log(m×n))

- Space complexity:
O(1)*/

# Code
```cpp []

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();    // rows
        int n = matrix[0].size(); // columns
        int low = 0;
        int high = m * n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};

```
