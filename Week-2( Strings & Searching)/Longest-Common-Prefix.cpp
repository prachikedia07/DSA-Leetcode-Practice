/*# Approach
There are two common approaches to solving the **Longest Common Prefix** problem. Both are efficient and commonly used:

### 🔹 Approach 1: Sorting-Based (Commented Out in Code)
- Sort the array of strings.
- The longest common prefix must be shared between the **first and last strings** in the sorted array.
- Compare characters of these two strings until they differ.

### 🔹 Approach 2: Horizontal Scanning (Implemented)
- Take the first string as the reference.
- For each of the remaining strings, compare character by character with the current prefix.
- Update the prefix length as needed.
- Return the substring of the original string up to the common length.

---*/

# Code
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        int i = 0;
        string s2 = strs[strs.size()-1];
        int j = 0;
        string ans = "";
        while(i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j]){
            ans += s1[i];
            i++; j++;
            }
            else
            break;
        }
        return ans;
        }
};
---


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s1 = strs[0];
        int ansLen = s1.size();
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < s1.size() && j < strs[i].size() && s1[j] == strs[i][j]) {
                j++;
            }
            ansLen = min(j, ansLen);
        }
        return s1.substr(0, ansLen);
    }
};
