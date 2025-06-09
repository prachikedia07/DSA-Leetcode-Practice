/*# Approach
Implement a custom version of atoi() that:
-Skips leading whitespaces
-Handles an optional sign (+ or -)
-Parses digits until a non-digit is found
-Clamps the result if it goes out of the 32-bit signed integer range: Range = [−2³¹, 2³¹ − 1] = [−2147483648, 2147483647]

# Complexity
- Time complexity:
O(n)

- Space complexity:
O(1)*/

# Code
```cpp []
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long res = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');
            if (sign * res <= INT_MIN)
                return INT_MIN;
            if (sign * res >= INT_MAX)
                return INT_MAX;
            i++;
        }
        return static_cast<int>(sign * res);
    }
};
```
