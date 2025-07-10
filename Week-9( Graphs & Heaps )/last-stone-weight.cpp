/*# Approach
-Push all stones into a max-heap.
-While size > 1:
-Pop two heaviest stones (stone1 and stone2).
-If stone1 != stone2, push the difference back.
-Return the remaining stone if any; else return 0.

# Complexity
- Time complexity:
O(n log n)

- Space complexity:
O(n)*/

# Code
```cpp []
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH;
        for(int stone : stones){
            maxH.push(stone);
        }
        while(maxH.size() > 1){
            int stone1 = maxH.top(); maxH.pop();
            int stone2 = maxH.top(); maxH.pop();
            if( stone1 != stone2)
            maxH.push(stone1 - stone2);
        }
        return maxH.empty() ? 0 : maxH.top();
    }
};
```
