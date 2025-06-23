/*# Approach
-We scan the number left to right and use a stack:
   At each digit, while k > 0 and the top of the stack is greater than the current digit, we pop the stack (i.e., remove the bigger digit).
-Then we push the current digit onto the stack.
-After the traversal:
    If k > 0, remove the last k digits from the stack.
-Finally:
   Convert the stack to a string.
   Remove leading zeroes.
   If the result is empty, return "0".

  */
# Code
```cpp []
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(char digit : num){
            while(!st.empty() && k>0 && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string res ;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        int idx = 0;
        while(idx < res.size() && res[idx] == '0'){
            idx++;
        }

        res = res.substr(idx);
        return res.empty() ? "0" : res;
    }
};
```
