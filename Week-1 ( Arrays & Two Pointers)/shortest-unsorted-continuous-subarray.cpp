/*
## Problem
Given an integer array `nums`, you need to find the shortest continuous subarray such that if you only sort this subarray in ascending order, the whole array becomes sorted.

Return the length of the shortest such subarray.

---

## Approach

The goal is to identify the boundaries (`subStart` and `subEnd`) of the subarray that needs to be sorted. The approach is as follows:

1. Traverse from the beginning to find the first index where the array is not increasing – this is the **start** of the unsorted subarray.
2. Traverse from the end to find the first index where the array is not decreasing – this is the **end** of the unsorted subarray.
3. Find the **minimum and maximum values** within this subarray.
4. Expand the `subStart` leftward if there are elements greater than `subMin`.
5. Expand the `subEnd` rightward if there are elements smaller than `subMax`.
6. The result is the length of the subarray from `subStart` to `subEnd`.

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
    int findUnsortedSubarray(vector<int>& nums) {
        int subStart = -1;
        int subEnd = -1;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                subStart = i;
                break;
            }
        }
        if (subStart == -1)
            return 0;

        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] < nums[i - 1]) {
                subEnd = i;
                break;
            }
        }

        int subMin = nums[subStart], subMax = nums[subStart];
        for (int i = subStart; i <= subEnd; i++) {
            subMin = min(subMin, nums[i]);
            subMax = max(subMax, nums[i]);
        }

        while (subStart > 0 && nums[subStart - 1] > subMin) {
            subStart--;
        }

        while (subEnd < nums.size() - 1 && nums[subEnd + 1] < subMax) {
            subEnd++;
        }

        return subEnd - subStart + 1;
    }
};
