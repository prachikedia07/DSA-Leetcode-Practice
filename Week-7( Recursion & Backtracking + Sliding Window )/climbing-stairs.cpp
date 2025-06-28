// The loop version is called bottom-up — it builds the answer step by step, and avoids repeating work.
# Code
```cpp []
class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
    //    return climbStairs(n-1) + climbStairs(n-2); recursive version
    int prev2 = 1;
    int prev1 = 1;
    int current = 0;
    for(int i=2; i<=n;i++){
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
    }
};
```
