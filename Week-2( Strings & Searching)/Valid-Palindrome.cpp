/*# Approach
We use the **two-pointer technique** to check whether a given string is a valid palindrome, considering **only alphanumeric characters** and **ignoring cases**.

1. Initialize two pointers: `left` at the start and `right` at the end of the string.
2. Skip all non-alphanumeric characters using `isalnum()`.
3. For valid characters, compare them after converting to lowercase using `tolower()`.
4. If any mismatch is found, return `false`. If all pairs match, return `true`.

This approach avoids extra space and is faster than copying/cleaning the string first.

---

# Complexity

- **Time complexity**: 
O(n)=

- **Space complexity**: 
O(1)*/

---

# Code
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
