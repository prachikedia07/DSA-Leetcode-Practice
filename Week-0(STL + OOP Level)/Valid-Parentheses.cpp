/*# Approach
 - Use stack for sequence validation
 - Use a loop to traverse every character of the string
 - Push open parenthesis into the stack 
 - Check if the top of the stack matches the bracket then pop from the stack
 - Finally if the stack remains empty in the end return true
 - Handle edge cases

# Complexity
- Time complexity:
  O(n)

- Space complexity:
   O(n)*/

# Code
```cpp []
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c=='(' || c=='{' || c=='['){
            st.push(c);
            }
            else{
                if(st.empty())
                return false;
                else if(c==')' && st.top() != '('||
                        c=='}' && st.top() != '{'||
                        c==']' && st.top() != '[')
                    return false;
                     st.pop();
            }
           
        }
        return st.empty();
    }
};
```
