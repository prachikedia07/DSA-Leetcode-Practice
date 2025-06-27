/*# Approach
-We use classic hashing approach
-Traverse all the elements of array and stop as soon as we find a duplicate element
-Return true if found, false otherwise


# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)*/

# Code
```cpp []
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int num: nums){
            if(seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};
```
