/*# Approach
- Use a variable lastNonZero starting at 0.
- Traverse the array.
- Every time you find a non-zero, put it at nums[lastNonZero], and increment lastNonZero.
- After that, fill remaining positions with 0. Or Use the swap version if you want fewer writes and slightly better performance in practice.

# Complexity
- Time complexity:
O(m)

- Space complexity:
O(1)*/

# Code
```cpp []
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[lastNonzero],nums[i]);
                lastNonzero++;
            }
        }
        // for(int i=lastNonzero;i<nums.size();i++){
        //     nums[i] = 0;
        // }
    }
};
```
