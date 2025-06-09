/*# Approach
We simply use a two pointer approach to swap the last and first elements of the string reversing them in the process.

# Complexity
- Time complexity:
O(n)
- Space complexity:
o(1)*/

# Code
```cpp []
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
          swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
```
