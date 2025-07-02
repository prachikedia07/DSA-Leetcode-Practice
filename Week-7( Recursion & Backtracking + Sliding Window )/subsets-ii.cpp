# Code
```cpp []
class Solution {
public:
    void backtrack(int start, vector<int>& nums, vector<int>& subset,
                   vector<vector<int>>& result) {
        result.push_back(subset); // Add current subset

        for (int i = start; i < nums.size(); ++i) {
            // Skip duplicates at same recursive depth
            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]);
            backtrack(i + 1, nums, subset, result);
            subset.pop_back(); // backtrack
        }
    }
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // Step 1: Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(0, nums, subset, result);
    return result;
}
};
```
