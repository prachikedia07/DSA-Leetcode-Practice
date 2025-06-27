/*
# Approach
- Create a helper function to compute the sum of the squares of digits of a number.
- Use a hash set to keep track of numbers already seen to detect loops.
- Continuously replace the number with the sum of the squares of its digits.
- If you reach 1, return true (happy number).
- If you see a repeated number before reaching 1, return false (cycle detected).

# Complexity
- Time complexity:
O(logn)

- Space complexity:
O(1)
*/

# Code
```cpp []
class Solution {
public:
int sumOfsquare(int n){
    int sum = 0;
    while(n>0){
        int digit = n % 10;
        sum += digit*digit;
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        unordered_set<int> seen;
        while( n != 1 && !seen.count(n)){
            seen.insert(n);
            n = sumOfsquare(n);
        }
        return n==1;
    }
};
```
