/*# Approach
We use hashing to store all unique elements from `nums1` in an `unordered_set` for O(1) average-time lookups.  
Then, we iterate through `nums2` and check if the current number exists in the set.  
If it does, we insert it into the result set (to ensure uniqueness in the final result).  
Finally, we convert the result set to a vector and return it.

# Complexity
- **Time complexity:**  
  $$O(n + m)$$  
  where `n` is the size of `nums1` and `m` is the size of `nums2`.  
 
- **Space complexity:**  
  $$O(n + r)$$  
  where `r` is the number of unique common elements.  */
 

# Code
```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> res;
     
        for (int num2 : nums2) {
            if (set1.count(num2)) {
                res.insert(num2);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};
