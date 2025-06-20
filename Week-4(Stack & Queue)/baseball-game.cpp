/*# Approach
We use a **stack** to simulate the points system as described in the problem.  
Each operation is handled based on its type:
- If it's an integer string, we convert and push it.
- `"+"`: Push the sum of the last two scores.
- `"D"`: Push double the last score.
- `"C"`: Remove the last valid score.

We then sum up all the values in the stack to get the final result.

# Complexity
- **Time complexity:** $$O(n)$$  
  We iterate through the operations once, and each stack operation (push/pop) is $$O(1)$$.

- **Space complexity:** $$O(n)$$  
  In the worst case, all operations are valid integers and are pushed to the stack.*/

# Code
```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }
            else if (operations[i] == "D")
                st.push(2 * st.top());
            else if (operations[i] == "C")
                st.pop();
            else
                st.push(stoi(operations[i]));
        }
        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        return total;
    }
};
