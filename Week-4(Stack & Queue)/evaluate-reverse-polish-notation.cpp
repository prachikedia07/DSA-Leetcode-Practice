/*# Approach
-Use a stack<int>.
-Iterate through the tokens.
-If it's a number → push to stack.
-If it's an operator → pop two values, evaluate, push result.


*/

# Code
```cpp []
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" ||
                tokens[i] == "/") {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                int sum = 0;
                if(tokens[i] == "+") sum = val2 + val1;
                else if(tokens[i] == "-") sum = val2 - val1;
                else if(tokens[i] == "*") sum = val2 * val1;
                else if(tokens[i] == "/") sum = val2 / val1;
                st.push(sum);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
```
