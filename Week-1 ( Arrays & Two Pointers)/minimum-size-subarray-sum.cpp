/*# Approach
This problem is solved using the **two-pointer (sliding window)** technique.

1. Initialize two pointers, `low` and `high`, both starting at the beginning of the array.
2. Expand the window by moving `high` and adding elements to `currSum`.
3. Once `currSum` is greater than or equal to the target, attempt to shrink the window from the left (`low`) to minimize the length while still maintaining the required sum.
4. Update `minLen` with the minimum window size found.
5. Return `0` if no valid subarray is found (i.e. `minLen` is still `INT_MAX`), else return `minLen`.

This efficient sliding window approach avoids checking all subarrays explicitly.

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
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int currSum = 0;
        int high = 0, low = 0;

        while (high < nums.size()) {
            currSum += nums[high];
            high++;

            while (currSum >= target) {
                int currLen = high - low;
                minLen = min(minLen, currLen);
                currSum -= nums[low];
                low++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
