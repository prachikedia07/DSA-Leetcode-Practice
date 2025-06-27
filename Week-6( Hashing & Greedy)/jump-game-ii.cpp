/*# Approach
We use a greedy approach to solve the problem efficiently. The idea is to always jump to the farthest reachable index in the current jump range. 

We keep track of:
- `farthest`: the farthest index we can reach so far,
- `end`: the end of the current jump range,
- `jumps`: the number of jumps made.

We iterate through the array (excluding the last element), and for each index, update the `farthest` reachable index. If we reach the end of the current jump range, we increment the number of `jumps` and update `end` to the `farthest`.

# Complexity
- **Time complexity:**  
  $$O(n)$$ — We traverse the array once.

- **Space complexity:**  
  $$O(1)$$ — No extra space is used besides a few variables.*/

# Code
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, end = 0, farthest = 0;
        for(int i = 0; i < n - 1 ; i++) {
            farthest = max(farthest, i + nums[i]);
            if(i == end) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};
