/*# Approach
- We use a two-pass greedy algorithm:
 **Left to Right Pass**:  
- Iterate through the `ratings` array. If a child has a higher rating than the previous one, give them one more candy than the previous child.
 **Right to Left Pass**:  
- Iterate from the end. If a child has a higher rating than the next one, update their candy count to be the maximum of their current count and one more than the next child.
- Finally, sum up all the candies to get the minimum total required.

# Complexity
- **Time complexity:** 
$$O(n)$$  
  Two linear passes through the array.

- **Space complexity:** 
$$O(n)$$  
  We use an additional array `candies` of size `n`.*/

# Code
```cpp
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        // Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to Left + Sum
        int sum = candies[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
            sum += candies[i];
        }

        return sum;
    }
};
