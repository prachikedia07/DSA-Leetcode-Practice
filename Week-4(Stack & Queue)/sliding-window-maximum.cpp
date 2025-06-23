/*# Approach
We use a deque to store indices in decreasing order of their values in the window as it allows popping from both ends.
-Loop through each index i in nums.
-Remove indices from the back of the deque if nums[i] is greater than or equal to them.
-Remove the front index if it's out of the current window.
-Add current index i to the deque.
-Once i >= k - 1, the front of the deque is the max of the current window.

# Complexity
- Time complexity:
O(N)

- Space complexity:
O(N)*/

# Code
```cpp []
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
```
