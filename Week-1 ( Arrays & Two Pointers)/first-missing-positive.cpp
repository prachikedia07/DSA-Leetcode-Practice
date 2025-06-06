/*
## Problem
Given an unsorted integer array `nums`, return the smallest missing positive integer.

You must implement an algorithm that runs in **O(n)** time and uses **constant extra space**.

---

## Approach

The key observation is that the smallest missing positive integer must lie in the range `[1, n + 1]`, where `n` is the size of the array.

### Steps:
1. Iterate through the array and for each number `nums[i]`, place it at its correct position `nums[i] - 1` if:
   - `nums[i]` is in the range `[1, n]`
   - `nums[i]` is not already in the correct position
2. After rearranging, iterate through the array again and check the first index `i` where `nums[i] != i + 1`.
3. That means `i + 1` is the smallest missing positive number.
4. If all numbers from `1` to `n` are present, return `n + 1`.

---

## Complexity

- **Time Complexity:** 
O(n)

- **Space Complexity:** 
O(1)

---*/

## Code

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n &&
                   nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};
