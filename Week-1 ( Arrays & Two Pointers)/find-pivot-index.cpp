/*# Approach
To find the pivot index, we use the idea that at the pivot, the sum of the elements to the left should be equal to the sum of the elements to the right.

1. First, compute the total sum of the array.
2. Then, iterate through the array while maintaining the left sum (`sumLeft`).
3. For each index `i`, calculate the right sum as `totalSum - sumLeft - nums[i]`.
4. If `sumLeft == sumRight`, return the current index as the pivot.
5. If no such index is found, return `-1`.

This approach avoids recomputing the left and right sums on each iteration, making it efficient.

---

# Complexity
- Time complexity:  
 O(n)

- Space complexity:  
  O(1)*/

---

# Code
```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0;
        int sumRight;
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < nums.size(); i++) {
            sumRight = totalSum - sumLeft - nums[i];
            if (sumLeft == sumRight)
                return i;
            sumLeft += nums[i];
        }

        return -1;
    }
};

```
