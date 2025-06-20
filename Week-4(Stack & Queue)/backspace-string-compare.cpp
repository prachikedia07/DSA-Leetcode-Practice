✅ Stack-Based Approach — used in Week 4 (Stack & Queue focus)
//   # Approach
//     Use a stack to simulate typing:
//     Iterate through each character:
//     If it’s a letter, push to stack.
//     If it’s '#', pop from stack (if not empty).
//     After full iteration, convert the stack to a string.
// # Complexity
// - Time complexity:
// O(n2 + m2)
// - Space complexity:
// O(n + m)

# Code
```cpp []
class Solution {
public:
string Final(string str){
int i = 0;
        stack<char> st;
        while(i<str.size()){
            if(str[i] == '#' ) {
               if(!st.empty()) 
            st.pop();
            }
            else {
                st.push(str[i]);
            }
            i++;
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
}
    bool backspaceCompare(string s, string t) {
    return Final(s) == Final(t);
    }
};
```


✅ Two-Pointer Optimized — O(1) space; useful in interviews

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            // Process backspaces in s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++; i--;
                } else if (skipS > 0) {
                    skipS--; i--;
                } else {
                    break;
                }
            }

            // Process backspaces in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++; j--;
                } else if (skipT > 0) {
                    skipT--; j--;
                } else {
                    break;
                }
            }

            // Compare current valid characters
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) return false;
            } else {
                if (i >= 0 || j >= 0) return false;
            }

            i--; j--;
        }

        return true;
    }
};

