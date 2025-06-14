/*# Approach
-Extract the current bits from both strings.
-Add them along with the carry.
-Append the result of sum % 2 to the result string (this is the current bit).
-Update the carry to sum / 2.
-Continue this process while there are bits remaining in either string or there's a carry.
-Finally, reverse the result string since we've built it from least to most significant bit.

# Complexity
- Time complexity:
O(max(n,m))
- Space complexity:
O(max(n,m))*/

# Code
```cpp []
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        while (i >= 0 || j >= 0 || carry != 0) {
            int bitA = 0;
            int bitB = 0;
            if (i >= 0) {
                bitA = a[i] - '0'; // ASCII values => 49 - 48 = 1
                i--;
            }
            if (j >= 0) {
                bitB = b[j] - '0';
                j--;
            }
            int sum = bitA + bitB + carry;
            result.push_back((sum % 2) + '0' );
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```
