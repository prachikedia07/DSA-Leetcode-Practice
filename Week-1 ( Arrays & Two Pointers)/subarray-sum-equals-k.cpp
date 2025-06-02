/*# Approach
We use the prefix sum technique along with a hashmap to count the number of subarrays whose sum equals `k`.

1. Maintain a running prefix sum (`prefixsum`) while traversing the array.
2. Use an unordered map (`prefixsumFreq`) to store how many times each prefix sum has occurred.
3. At each step, check if `prefixsum - k` exists in the map. If it does, it means there's a subarray ending at the current index with sum `k`, and we add the frequency of `prefixsum - k` to the count.
4. Update the map with the current `prefixsum`.

This approach avoids checking all possible subarrays explicitly and reduces the time complexity significantly.

---

# Complexity
- Time complexity:  
  O(n)

- Space complexity:  
  O(n)*/

---

# Code
```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixsum = 0;
        unordered_map<int, int> prefixsumFreq;
        prefixsumFreq[0] = 1;
    
        for (int num : nums) {
            prefixsum += num;
            if (prefixsumFreq.find(prefixsum - k) != prefixsumFreq.end())
                count += prefixsumFreq[prefixsum - k];
            prefixsumFreq[prefixsum]++;
        }

        return count;
    }
};
