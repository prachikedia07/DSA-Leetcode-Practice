/*# Approach
The idea is to traverse each character in the string and treat it as a potential center of a palindrome, trying to expand around it in both directions while checking if the expanded substring remains a palindrome. 

For each position, we check for both odd-length palindromes (where the current character is the center) and even-length palindromes (where the current character and the next character together form the center).
 As we expand outward from each center, we keep track of the start position and length of the longest palindrome found so far, updating these values whenever we find a longer valid palindrome.

# Complexity
- Time complexity:
O(n2)

- Space complexity:
O(1)*/

# Code
```cpp []
class Solution {
public:
string expandCenter(string &s, int left, int right){
    while(left>=0 && right<s.length() && s[left] == s[right]){
        left--;
        right++;
    }
    return s.substr(left+1, right - left - 1);
}
    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0; i< s.length();i++){
            string odd = expandCenter(s,i,i);
            string even = expandCenter(s,i,i+1);
            if(odd.length()> longest.length())
            longest = odd;
            if(even.length()> longest.length())
            longest = even;
        }
        return longest;
    }
};
```
