/*

# Approach
-Traverse the string:
   Push indices of '(' into an open stack.
   Push indices of '*' into a star stack.
   For ')', try to pop from open; if not available, try star. If neither, it's invalid.
-After traversal:
   Match any remaining '(' in open with later '*' in star.
   If open.top() > star.top(), then the '*' is before '(' → invalid.
-If all '(' are matched, return true.


# Complexity
- Time complexity:
O(n) 

- Space complexity:
O(n) */

# Code
```cpp []
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> open;
        stack<char> star;
        for(int i = 0; i<s.length();i++ ){
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') star.push(i);
            else {
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;
            }
        }
        while(!open.empty() && !star.empty()){
            if(open.top() > star.top()) return false;
            open.pop();
            star.pop();
        }
        return open.empty();
    }
};
```
