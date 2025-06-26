/*# Approach
-Count frequency using a hash map.
-Create a bucket array: vector<vector<int>> buckets(n + 1).
-Place elements in buckets by frequency.
   Bucket Sort Approach Idea:
        - Frequency of each element is at most n, so we can group numbers by how frequent they are using an array of buckets.
        - Then, traverse the buckets from high frequency to low and collect the top k elements.
-Traverse from the highest bucket and collect k elements.

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(n)*/

# Code
```cpp []
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> result;
        for(int num : nums) freq[num]++;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1);
        for(auto& [num, count] : freq){
            buckets[count].push_back(num);
        }
        for(int i = n; i>=0 && result.size() < k; i--){
            for(int num : buckets[i]){
                result.push_back(num);
                if(result.size() == k) break;
            }
        }
        return result;
    }
};
```
