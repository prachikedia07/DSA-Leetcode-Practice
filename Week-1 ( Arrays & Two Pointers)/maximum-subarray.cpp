/*
### 🚀 Approach
We use **Kadane’s Algorithm**, which efficiently finds the maximum subarray sum in **linear time**.

- Initialize two variables:
  - `currSum`: Tracks the **current subarray sum**
  - `maxSum`: Tracks the **maximum subarray sum found so far**
- Traverse the array from index `1` onward:
  - At each step, decide whether to:
    - **Start a new subarray** at the current element, or
    - **Extend the previous subarray**
  - Update `currSum` as the **maximum of current element or (currSum + current element)**
  - Update `maxSum` with the **maximum of currSum and maxSum**

---

### 📊 Complexity

- **Time complexity:** 
O(n) 
 

- **Space complexity:**
O(1)  
 */

---

### 💻 Code
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
