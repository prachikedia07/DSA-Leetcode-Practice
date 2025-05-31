/*# Approach
 - Merge in-place from the back
 - Sort the new nums1 array after merging
 - Handle edge cases

# Complexity
- Time complexity:
 O((m + n) log (m + n)) → due to sorting

- Space complexity:
 O(1) extra → sorting in-place*/

# Code
```cpp []
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[i+m]= nums2[i];
            }
            sort(nums1.begin(),nums1.end() );
        }
   };
```
