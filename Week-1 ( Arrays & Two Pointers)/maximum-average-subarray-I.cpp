/*# Approach
We use a **sliding window technique** to find the maximum average of any contiguous subarray of size `k`.

- Initialize two pointers: `low` and `high` to represent the window boundaries.
- Calculate the sum of the first window of size `k`.
- Slide the window forward by incrementing both pointers:
  - Subtract the element going out of the window (`nums[low]`)
  - Add the new element coming into the window (`nums[high]`)
- Keep track of the maximum sum encountered during the sliding process.
- Finally, return the maximum sum divided by `k` to get the maximum average.
- The result is rounded to 5 decimal places.

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
    double findMaxAverage(vector<int>& nums, int k) {
        int low = 0;
        int high = low + (k-1);
        double currSum = 0;
        for(int i = 0; i <= high; i++){
            currSum += nums[i];
        }
        double maxSum = currSum;
        while(high < nums.size() - 1){
            high++;
            currSum = currSum - nums[low] + nums[high];
            low++;
            maxSum = max(currSum, maxSum);
        }
        double result = maxSum / (double)k;
        return round(result * 100000.0) / 100000.0;
    }
};
