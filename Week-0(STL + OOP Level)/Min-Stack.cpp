/*# Approach
   - Maintain min with two stacks or stack of pairs
   - I have used a stack of two pairs to solve this question however you can initialize two stacks too if it helps you better. Both are a good way and offers same time complexities.

# ✅ When to Use Which?
 Use Pair Approach when:
  1. You want cleaner code .
  2. You want only one stack to reduce object count or simplify debugging.
Use Two Stacks when:
  1. You want slightly better space optimization .
  2. You want more explicit separation of values and minimums .



# Complexity
- Time complexity:
  O(1)

- Space complexity:
   for push O(n)
   for all else O(1)*/

# Code
```cpp []
class MinStack {
public:
stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty())
        st.push({val,val});
        else
        st.push({val,min(val,st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
       return st.top().first;
    }
    
    int getMin() {
       return st.top().second;
    }
};
