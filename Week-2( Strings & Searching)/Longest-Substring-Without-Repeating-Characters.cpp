/*# Approach
We use the **sliding window** technique along with an `unordered_set` to track characters in the current substring window.

1. Initialize two pointers `start` and `end` to define the current window.
2. As we iterate with `end`, if `s[end]` is **not in the set**, add it and update the maximum length.
3. If it **already exists** in the set, it means we have a duplicate character. So:
   - We remove characters from the `start` pointer side until the duplicate is removed.
4. At every step, we update `maxLen` with the current window length: `end - start + 1`.

This ensures we only process each character at most twice — once when added and once when removed — leading to optimal time complexity.

---

# Complexity

- **Time complexity**: $$O(n)$$  
  Each character is visited at most twice (once by `end`, once by `start`), so the overall time is linear.

- **Space complexity**: $$O(k)$$  
  Where `k` is the number of unique characters in the string. In the worst case, this could be `O(n)` if all characters are distinct.

---*/

# Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c;
        int start = 0;
        int maxLen = 0;

        for (int end = 0; end < s.length(); end++) {
            while (c.find(s[end]) != c.end()) {
                c.erase(s[start]);
                start++;
            }
            c.insert(s[end]);
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
