// For example, for n = 3
//  "" 
//  ├── "(" 
//  │   ├── "((" 
//  │   │   ├── "(((" 
//  │   │   │   ├── "((()" 
//  │   │   │   │   ├── "((())" 
//  │   │   │   │   │   └── "((()))" ✅
//  │   │   │   │   └── "(()()" ❌ invalid (can't close more than open)
//  │   │   │   └── "(()(" 
//  │   │   │       ├── "(()()" 
//  │   │   │       │   ├── "(()())" ✅
//  │   │   │       └── "(())(" 
//  │   │   │           ├── "(())()" ✅
//  │   │   └── "(()" 
//  │   │       └── "(()()" ...
//  │   └── "(()" (backtrack and try other options)
//  └── "(" ...
// Final result becomes { ((())), (()()), (())(), ()(()), ()()() }


# Code
```cpp []
class Solution {
public:
void backtrack(int open, int close, string curr, vector<string>& res, int n){
    if(curr.length() == 2*n){
        res.push_back(curr);
        return;
    }
    if(open < n)
    backtrack(open + 1, close, curr + '(', res, n);
    
    if(close < open)
    backtrack(open, close + 1, curr + ')', res, n);
}
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(0, 0, "", res, n);
        return res;
    }
};
```
